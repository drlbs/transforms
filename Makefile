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

segments.o : segments.c
	$(CC) $(CFLAGS) segments.c -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *

