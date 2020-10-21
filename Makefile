# This sample Makefile allows you to make an OpenGL application
#   whose source is exactly one .c or .cc file.
#
#

CC = gcc
C++ = g++ 
LDLIBS =  -lglut -lGL -lGLU -lm

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 
endif


all: segments

segments :	segments.o
	$(CC) $(CFLAGS) segments.o -o segments $(LDLIBS)

segments.o : segments.cc
	$(CC) $(CFLAGS) segments.cc -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *

