#   $OpenBSD: Makefile,v 1.14 2006/10/30 20:25:48 otto Exp $

.PHONY: all clean

HOSTCC?=gcc
HOSTCXX?=g++
HOSTCPP?=cpp
HOSTLD?=ld
HOSTAR?=ar
YACC=yacc
LEX=lex

PROG=	config
SRCS=	files.c y.tab.c hash.c main.c mkheaders.c mkioconf.c \
			mkmakefile.c mkswap.c pack.c lex.yy.c sem.c util.c \
				misc.c exec.c

OBJS=$(patsubst %.c, %.o, ${SRCS})

CFLAGS+= -I.

all:${PROG}

${PROG}:${OBJS}
	@echo "Generating config"
	@${HOSTCC} -o $@ $^
	@echo "Done"

${OBJS}:%o:%c
	${HOSTCC} -c $^

y.tab.c:
	${YACC} -d gram.y

lex.yy.c:
	${LEX} scan.l

clean:
	@-rm ${OBJS} 
	@-rm ${PROG}
	@-rm ./lex.yy.c
	@-rm ./y.tab.c
	@-rm ./y.tab.h
