/*	$OpenBSD: main.c,v 1.44 2012/06/22 22:02:29 guenther Exp $	*/
/*	$NetBSD: main.c,v 1.22 1997/02/02 21:12:33 thorpej Exp $	*/

/*
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This software was developed by the Computer Systems Engineering group
 * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and
 * contributed to Berkeley.
 *
 * All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Lawrence Berkeley Laboratories.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)main.c	8.1 (Berkeley) 6/6/93
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

int	firstfile(const char *);
int	yyparse(void);

extern char *optarg;
extern int optind;

static struct hashtab *mkopttab;
static struct nvlist **nextopt;
static struct nvlist **nextdefopt;
static struct nvlist **nextmkopt;

static __dead void stop(void);
static int do_option(struct hashtab *, struct nvlist ***,
    const char *, const char *, const char *);
static int crosscheck(void);
static int badstar(void);
static int mksymlinks(void);
static int hasparent(struct devi *);
static int cfcrosscheck(struct config *, const char *, struct nvlist *);
static void optiondelta(void);

int	madedir = 0;

int	verbose;

void
usage(void)
{
	extern char *__progname;

	fprintf(stderr,
		"usage: %s [-p] [-b builddir] [-s srcdir] [config-file]\n"
		"       %s [-u] [-f | -o outfile] -e infile\n",
		__progname, __progname);

	exit(1);
}

int
main(int argc, char *argv[])
{
	char *p;
	const char *last_component;
	char *outfile = NULL;
	int pflag, ch, eflag, uflag, fflag;

	pflag = eflag = uflag = fflag = 0;
	while ((ch = getopt(argc, argv, "egpfb:s:o:u")) != -1) {
		switch (ch) {

		case 'o':
			outfile = optarg;
			break;
		case 'u':
			uflag = 1;
			break;
		case 'f':
			fflag = 1;
			break;

		case 'e':
			eflag = 1;
			if (!isatty(STDIN_FILENO))
				verbose = 1;
			break;

		case 'g':
			/*
			 * In addition to DEBUG, you probably wanted to
			 * set "options KGDB" and maybe others.  We could
			 * do that for you, but you really should just
			 * put them in the config file.
			 */
			(void)fputs(
			    "-g is obsolete (use makeoptions DEBUG=\"-g\")\n",
			    stderr);
			usage();

		case 'p':
			/*
			 * Essentially the same as makeoptions PROF="-pg",
			 * but also changes the path from ../../compile/FOO
			 * to ../../compile/FOO.PROF; i.e., compile a
			 * profiling kernel based on a typical "regular"
			 * kernel.
			 *
			 * Note that if you always want profiling, you
			 * can (and should) use a "makeoptions" line.
			 */
			pflag = 1;
			break;

		case 'b':
			builddir = optarg;
			break;

		case 's':
			srcdir = optarg;
			break;

		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;
	if (argc > 1 || (eflag && argv[0] == NULL))
		usage();
#if 0
	if (eflag) {
#ifdef MAKE_BOOTSTRAP
		fprintf(stderr, "config: UKC not available in this binary\n");
		exit(1);
#else
		return (ukc(argv[0], outfile, uflag, fflag));
#endif
	}
#endif

	conffile = (argc == 1) ? argv[0] : "CONFIG";
	if (firstfile(conffile)) {
		(void)fprintf(stderr, "config: cannot read %s: %s\n",
		    conffile, strerror(errno));
		exit(2);
	}

	/*
	 * Init variables.
	 */
	minmaxusers = 1;
	maxmaxusers = 10000;
#if 1
	initintern();
	initfiles();
	initsem();
	devbasetab = ht_new();
	devatab = ht_new();
	selecttab = ht_new();
	needcnttab = ht_new();
	opttab = ht_new();
	mkopttab = ht_new();
	defopttab = ht_new();
	nextopt = &options;
	nextmkopt = &mkoptions;
	nextdefopt = &defoptions;

	/*
	 * Handle profiling (must do this before we try to create any
	 * files).
	 */
	last_component = strrchr(conffile, '/');
	last_component = (last_component) ? last_component + 1 : conffile;
	if (pflag) {
		int len = strlen(last_component) + 17;
		p = emalloc(len);
		(void)snprintf(p, len, "../compile/%s.PROF", last_component);
		(void)addmkoption(intern("PROF"), "-pg");
		(void)addoption(intern("GPROF"), NULL);
	} else {
		int len = strlen(last_component) + 12;
		p = emalloc(len);
		(void)snprintf(p, len, "../compile/%s", last_component);
	}
	defbuilddir = (argc == 0) ? "." : p;

	/*
	 * Parse config file (including machine definitions).
	 */
	if (yyparse())
		stop();

	/*
	 * Fix (as in `set firmly in place') files.
	 */
	if (fixfiles())
		stop();

	/*
	 * Fix objects and libraries.
	 */
	if (fixobjects())
		stop();

	/*
	 * Perform cross-checking.
	 */
	if (maxusers == 0) {
		if (defmaxusers) {
			(void)printf("maxusers not specified; %d assumed\n",
			    defmaxusers);
			maxusers = defmaxusers;
		} else {
			(void)fprintf(stderr,
			    "config: need \"maxusers\" line\n");
			errors++;
		}
	}
	if (crosscheck() || errors)
		stop();

	/*
	 * Squeeze things down and finish cross-checks (STAR checks must
	 * run after packing).
	 */
	pack();
	if (badstar())
		stop();

	/*
	 * Ready to go.  Build all the various files.
	 */
	if (mksymlinks() || mkmakefile() || mkheaders() || mkswap() ||
	    mkioconf())
		stop();
	optiondelta();
	exit(0);
#endif
}
#if 1
static int
mksymlink(const char *value, const char *path)
{
	int ret = 0;

	if (remove(path) && errno != ENOENT) {
		warn("config: remove(%s)", path);
		ret = 1;
	}
	if (symlink(value, path)) {
		warn("config: symlink(%s -> %s)", path, value);
		ret = 1;
	}
	return (ret);
}


/*
 * Make a symlink for "machine" so that "#include <machine/foo.h>" works,
 * and for the machine's CPU architecture, so that works as well.
 */
static int
mksymlinks(void)
{
	int ret;
	char *p, buf[MAXPATHLEN];
	const char *q;

	snprintf(buf, sizeof buf, "arch/%s/include", machine);
	p = sourcepath(buf);
	ret = mksymlink(p, "machine");
	if (machinearch != NULL) {
		snprintf(buf, sizeof buf, "arch/%s/include", machinearch);
		p = sourcepath(buf);
		q = machinearch;
	} else {
		p = strdup("machine");
		if (!p)
			errx(1, "out of memory");
		q = machine;
	}
	ret |= mksymlink(p, q);
	free(p);

	return (ret);
}

static __dead void
stop(void)
{
	(void)fprintf(stderr, "*** Stop.\n");
	exit(1);
}

/*
 * Define a standard option, for which a header file will be generated.
 */
void
defoption(const char *name)
{
	char *p, *low, c;
	const char *n;

	/*
	 * Convert to lower case.  The header file name will be
	 * in lower case, so we store the lower case version in
	 * the hash table to detect option name collisions.  The
	 * original string will be stored in the nvlist for use
	 * in the header file.
	 */
	low = emalloc(strlen(name) + 1);
	for (n = name, p = low; (c = *n) != '\0'; n++)
		*p++ = isupper(c) ? tolower(c) : c;
	*p = 0;

	n = intern(low);
	free(low);
	(void)do_option(defopttab, &nextdefopt, n, name, "defopt");

	/*
	 * Insert a verbatim copy of the option name, as well,
	 * to speed lookups when creating the Makefile.
	 */
	(void)ht_insert(defopttab, name, (void *)name);
}

/*
 * Remove an option.
 */
void
removeoption(const char *name)
{
	struct nvlist *nv, *nvt;
	char *p, *low, c;
	const char *n;

	if ((nv = ht_lookup(opttab, name)) != NULL) {
		if (options == nv) {
			options = nv->nv_next;
			nvfree(nv);
		} else {
			nvt = options;
			while (nvt->nv_next != NULL) {
				if (nvt->nv_next == nv) {
					nvt->nv_next = nvt->nv_next->nv_next;
					nvfree(nv);
					break;
				} else
					nvt = nvt->nv_next;
			}
		}
	}

	(void)ht_remove(opttab, name);

	low = emalloc(strlen(name) + 1);
	/* make lowercase, then remove from select table */
	for (n = name, p = low; (c = *n) != '\0'; n++)
		*p++ = isupper(c) ? tolower(c) : c;
	*p = 0;
	n = intern(low);
	free(low);
	(void)ht_remove(selecttab, n);
}

/*
 * Add an option from "options FOO".  Note that this selects things that
 * are "optional foo".
 */
void
addoption(const char *name, const char *value)
{
	char *p, *low, c;
	const char *n;

	if (do_option(opttab, &nextopt, name, value, "options"))
		return;

	low = emalloc(strlen(name) + 1);
	/* make lowercase, then add to select table */
	for (n = name, p = low; (c = *n) != '\0'; n++)
		*p++ = isupper(c) ? tolower(c) : c;
	*p = 0;
	n = intern(low);
	free(low);
	(void)ht_insert(selecttab, n, (void *)n);
}

/*
 * Add a "make" option.
 */
void
addmkoption(const char *name, const char *value)
{

	(void)do_option(mkopttab, &nextmkopt, name, value, "mkoptions");
}

/*
 * Add a name=value pair to an option list.  The value may be NULL.
 */
static int
do_option(struct hashtab *ht, struct nvlist ***nppp, const char *name,
    const char *value, const char *type)
{
	struct nvlist *nv;

	/* assume it will work */
	nv = newnv(name, value, NULL, 0, NULL);
	if (ht_insert(ht, name, nv) == 0) {
		**nppp = nv;
		*nppp = &nv->nv_next;
		return (0);
	}

	/* oops, already got that option */
	nvfree(nv);
	if ((nv = ht_lookup(ht, name)) == NULL)
		panic("do_option");
	if (nv->nv_str != NULL)
		error("already have %s `%s=%s'", type, name, nv->nv_str);
	else
		error("already have %s `%s'", type, name);
	return (1);
}

/*
 * Return true if there is at least one instance of the given unit
 * on the given device attachment (or any units, if unit == WILD).
 */
int
deva_has_instances(struct deva *deva, int unit)
{
	struct devi *i;

	if (unit == WILD)
		return (deva->d_ihead != NULL);
	for (i = deva->d_ihead; i != NULL; i = i->i_asame)
		if (unit == i->i_unit)
			return (1);
	return (0);
}

/*
 * Return true if there is at least one instance of the given unit
 * on the given base (or any units, if unit == WILD).
 */
int
devbase_has_instances(struct devbase *dev, int unit)
{
	struct deva *da;

	for (da = dev->d_ahead; da != NULL; da = da->d_bsame)
		if (deva_has_instances(da, unit))
			return (1);
	return (0);
}

static int
hasparent(struct devi *i)
{
	struct nvlist *nv;
	int atunit = i->i_atunit;

	/*
	 * We determine whether or not a device has a parent in in one
	 * of two ways:
	 *	(1) If a parent device was named in the config file,
	 *	    i.e. cases (2) and (3) in sem.c:adddev(), then
	 *	    we search its devbase for a matching unit number.
	 *	(2) If the device was attach to an attribute, then we
	 *	    search all attributes the device can be attached to
	 *	    for parents (with appropriate unit numbers) that
	 *	    may be able to attach the device.
	 */

	/*
	 * Case (1): A parent was named.  Either it's configured, or not.
	 */
	if (i->i_atdev != NULL)
		return (devbase_has_instances(i->i_atdev, atunit));

	/*
	 * Case (2): No parent was named.  Look for devs that provide the attr.
	 */
	if (i->i_atattr != NULL)
		for (nv = i->i_atattr->a_refs; nv != NULL; nv = nv->nv_next)
			if (devbase_has_instances(nv->nv_ptr, atunit))
				return (1);
	return (0);
}

static int
cfcrosscheck(struct config *cf, const char *what, struct nvlist *nv)
{
	struct devbase *dev;
	struct devi *pd;
	int errs, devminor;

	if (maxpartitions <= 0)
		panic("cfcrosscheck");

	for (errs = 0; nv != NULL; nv = nv->nv_next) {
		if (nv->nv_name == NULL)
			continue;
		dev = ht_lookup(devbasetab, nv->nv_name);
		if (dev == NULL)
			panic("cfcrosscheck(%s)", nv->nv_name);
		devminor = minor(nv->nv_int) / maxpartitions;
		if (devbase_has_instances(dev, devminor))
			continue;
		if (devbase_has_instances(dev, STAR) &&
		    devminor >= dev->d_umax)
			continue;
		for (pd = allpseudo; pd != NULL; pd = pd->i_next)
			if (pd->i_base == dev && devminor < dev->d_umax &&
			    devminor >= 0)
				goto loop;
		(void)fprintf(stderr,
		    "%s:%d: %s says %s on %s, but there's no %s\n",
		    conffile, cf->cf_lineno,
		    cf->cf_name, what, nv->nv_str, nv->nv_str);
		errs++;
loop:
		;
	}
	return (errs);
}

/*
 * Cross-check the configuration: make sure that each target device
 * or attribute (`at foo[0*?]') names at least one real device.  Also
 * see that the root, swap, and dump devices for all configurations
 * are there.
 */
int
crosscheck(void)
{
	struct devi *i;
	struct config *cf;
	int errs;

	errs = 0;
	for (i = alldevi; i != NULL; i = i->i_next) {
		if (i->i_at == NULL || hasparent(i))
			continue;
		xerror(conffile, i->i_lineno,
		    "%s at %s is orphaned", i->i_name, i->i_at);
		(void)fprintf(stderr, " (%s %s declared)\n",
		    i->i_atunit == WILD ? "nothing matching" : "no",
		    i->i_at);
		errs++;
	}
	if (allcf == NULL) {
		(void)fprintf(stderr, "%s has no configurations!\n",
		    conffile);
		errs++;
	}
	for (cf = allcf; cf != NULL; cf = cf->cf_next) {
		if (cf->cf_root != NULL) {	/* i.e., not swap generic */
			errs += cfcrosscheck(cf, "root", cf->cf_root);
			errs += cfcrosscheck(cf, "swap", cf->cf_swap);
			errs += cfcrosscheck(cf, "dumps", cf->cf_dump);
		}
	}
	return (errs);
}

/*
 * Check to see if there is a *'d unit with a needs-count file.
 */
int
badstar(void)
{
	struct devbase *d;
	struct deva *da;
	struct devi *i;
	int errs, n;

	errs = 0;
	for (d = allbases; d != NULL; d = d->d_next) {
		for (da = d->d_ahead; da != NULL; da = da->d_bsame)
			for (i = da->d_ihead; i != NULL; i = i->i_asame) {
				if (i->i_unit == STAR)
					goto foundstar;
			}
		continue;
	foundstar:
		if (ht_lookup(needcnttab, d->d_name)) {
			(void)fprintf(stderr,
		    "config: %s's cannot be *'d until its driver is fixed\n",
			    d->d_name);
			errs++;
			continue;
		}
		for (n = 0; i != NULL; i = i->i_alias)
			if (!i->i_collapsed)
				n++;
		if (n < 1)
			panic("badstar() n<1");
	}
	return (errs);
}

/*
 * Verify/create builddir if necessary, change to it, and verify srcdir.
 * This will be called when we see the first include.
 */
void
setupdirs(void)
{
	struct stat st;

	/* srcdir must be specified if builddir is not specified or if
	 * no configuration filename was specified. */
	if ((builddir || strcmp(defbuilddir, ".") == 0) && !srcdir) {
		error("source directory must be specified");
		exit(1);
	}

	if (srcdir == NULL)
		srcdir = "../../../..";
	if (builddir == NULL)
		builddir = defbuilddir;

	if (stat(builddir, &st) != 0) {
		if (mkdir(builddir, 0777)) {
			(void)fprintf(stderr, "config: cannot create %s: %s\n",
			    builddir, strerror(errno));
			exit(2);
		}
		madedir = 1;
	} else if (!S_ISDIR(st.st_mode)) {
		(void)fprintf(stderr, "config: %s is not a directory\n",
		    builddir);
		exit(2);
	}
	if (chdir(builddir) != 0) {
		(void)fprintf(stderr, "config: cannot change to %s\n",
		    builddir);
		exit(2);
	}
	if (stat(srcdir, &st) != 0 || !S_ISDIR(st.st_mode)) {
		(void)fprintf(stderr, "config: %s is not a directory\n",
		    srcdir);
		exit(2);
	}
}

struct opt {
	const char *name;
	const char *val;
};

int
optcmp(const void *v1, const void *v2)
{
	const struct opt *sp1 = v1, *sp2 = v2;
	int r;

	r = strcmp(sp1->name, sp2->name);
	if (r == 0) {
		if (!sp1->val && !sp2->val)
			r = 0;
		else if (sp1->val && !sp2->val)
			r = -1;
		else if (sp2->val && !sp1->val)
			r = 1;
		else r = strcmp(sp1->val, sp2->val);
	}
	return (r);
}

void
optiondelta(void)
{
	struct nvlist *nv;
	char nbuf[BUFSIZ], obuf[BUFSIZ];	/* XXX size */
	int nnewopts, ret = 0, i;
	struct opt *newopts;
	FILE *fp;

	for (nnewopts = 0, nv = options; nv != NULL; nv = nv->nv_next)
		nnewopts++;
	newopts = (struct opt *)emalloc(nnewopts * sizeof(struct opt));
	if (newopts == NULL)
		ret = 0;
	for (i = 0, nv = options; nv != NULL; nv = nv->nv_next, i++) {
		newopts[i].name = nv->nv_name;
		newopts[i].val = nv->nv_str;
	}
	qsort(newopts, nnewopts, sizeof (struct opt), optcmp);

	/* compare options against previous config */
	if ((fp = fopen("options", "r"))) {
		for (i = 0; !feof(fp) && i < nnewopts && ret == 0; i++) {
			if (newopts[i].val)
				snprintf(nbuf, sizeof nbuf, "%s=%s\n",
				    newopts[i].name, newopts[i].val);
			else
				snprintf(nbuf, sizeof nbuf, "%s\n",
				    newopts[i].name);
			if (fgets(obuf, sizeof obuf, fp) == NULL ||
			    strcmp(nbuf, obuf))
				ret = 1;
		}
		fclose(fp);
		fp = NULL;
	} else
		ret = 1;

	/* replace with the new list of options */
	if ((fp = fopen("options", "w+"))) {
		rewind(fp);
		for (i = 0; i < nnewopts; i++) {
			if (newopts[i].val)
				fprintf(fp, "%s=%s\n", newopts[i].name,
				    newopts[i].val);
			else
				fprintf(fp, "%s\n", newopts[i].name);
		}
		fclose(fp);
	}
	free(newopts);
	if (ret == 0 || madedir == 1)
		return;
	(void)printf("Kernel options have changed -- you must run \"make clean\"\n");
}
#endif
