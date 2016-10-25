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
LIBDIRS = -L/usr/X11R6/lib
INCDIRS = -I/usr/X11R6/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

.c:
	$(CC)  $@.c $(INCDIRS) $(LIBDIRS) $(LDLIBS) -o $@


.cc:
	$(C++)  -O $@.cc $(INCDIRS) $(LIBDIRS) $(LDLIBS) -o $@
