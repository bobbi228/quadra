# Makefile pour le Universal Game Skelton
# $Id$

include config/target.mk

ARFLAGS:=rcs
CXXFLAGS+=-pipe -pedantic -Wall -Iinclude -I../images

# FIXME: ugly hack to accomodate variable spot for the Berkely DB
# header on various distributions.
CXXFLAGS+=-I/usr/include/db3

OPTFLAGS+=-m486 -O6
DEBUGFLAGS=-ggdb

ifdef RELEASE
CXX=g++
CXXFLAGS+=$(OPTFLAGS)
else
CXXFLAGS+=$(DEBUGFLAGS) -D_DEBUG
endif

ifdef SOCKS
CXXFLAGS+=-DSOCKS
endif

ifeq "$(TARGET)" "linux"
CXXFLAGS+=-DUGS_LINUX -DUGS_LINUX_SVGA -DUGS_LINUX_X11
LDLIBS+=-L/usr/X11R6/lib -lX11 -lXext -lXpm -lvga -lvgagl -lz -ldb
else
# hmm, nothing else than linux is supported by this Makefile!
endif
