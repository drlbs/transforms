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

debug ?= n
ifeq ($(debug), y)
    CCFLAGS += -g -DDEBUG
else
    CCFLAGS += -O2 
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

