# This sample Makefile allows you to make an OpenGL application
#   whose source is exactly one .c or .cc file.
#
#
# To use this Makefile, you type:
#
#        make xxxx
#                  
# where
#       xxxx.c is the name of the file you wish to compile 
#       
# A binary named xxxx will be produced

CC = gcc
C++ = g++ 
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = prototypes.h
OBJS = matrix.o 

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 
endif


all: segments tags

segments :	segments.o $(OBJS) 
	$(CC) $(CFLAGS) segments.o $(OBJS) -o segments $(LDLIBS)

segments.o : segments.cc $(HEADERS)
	$(CC) $(CFLAGS) segments.cc -c

matrix.o : matrix.cc $(HEADERS)
	$(CC) $(CFLAGS) matrix.cc -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *

tags:
	ctags *.cc *.h
