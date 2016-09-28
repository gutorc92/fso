#
# Makefile
#

#Compile
CC=gcc

#Flags used to compile files
CFLAGS      = -g -Wall --std=c99
CURRENT_DIR = $(shell pwd)
SHAREDFLAGS = -lprimo -L. -Wl,-rpath,$(CURRENT_DIR)
LM          = -lm
FPIC        = -fPIC
SHARED      = -shared $(FPIC)

# Name of the executable files
# Prog do not user dinamic libraries
TARGET=prog
# Prog2 uses dinamic libraries
TARGET2=prog2

#Files
MAIN    = main.c
OBJMAIN = main.o

DEPS    = libprimo.h
LIB     = libprimo.c
OBJLIB  = libprimo.o
LIBSO   = libprimo.so

all: $(TARGET) clear $(TARGET2)

$(TARGET):
	$(CC) $(CFLAGS) -c -o $(OBJLIB) $(LIB)
	$(CC) $(CFLAGS) -c -o $(OBJMAIN) $(MAIN) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJMAIN) $(OBJLIB) $(LM)

$(TARGET2):
	$(CC) -c $(CFLAGS) $(FPIC) $(LIB) 
	$(CC) $(SHARED) -o $(LIBSO) $(OBJLIB) 
	$(CC) $(CFLAGS) -o $(TARGET2) $(MAIN) $(LIBSO) $(SHAREDFLAGS) $(LM)	 

clear:
	rm -f *.o 

clean:
	rm -f $(TARGET) $(TARGET2)  *.o *.so
