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
LDL		    = -ldl

# Name of the executable files
# Prog do not user dinamic libraries
TARGET   = prog
# Prog2 uses dinamic libraries
TARGET2  = prog2
# Prog3 uses dlfcn librarie
TARGET3  = prog3

#Files
MAIN     = main.c
OBJMAIN  = main.o
MAIN3    = main3.c
OBJMAIN3 = main3.o

DEPS     = libprimo.h
LIB      = libprimo.c
OBJLIB   = libprimo.o
LIBSO    = libprimo.so

all: $(TARGET) clear $(TARGET2) $(TARGET3)

$(TARGET):
	$(CC) $(CFLAGS) -c -o $(OBJLIB) $(LIB) $(LM)
	$(CC) $(CFLAGS) -c -o $(OBJMAIN) $(MAIN) $(LM)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJMAIN) $(OBJLIB) $(LM)

$(TARGET2):
	$(CC) -c $(CFLAGS) $(FPIC) $(LIB) $(LM)
	$(CC) $(SHARED) -o $(LIBSO) $(OBJLIB) $(LM)
	$(CC) $(CFLAGS) -o $(TARGET2) $(MAIN) $(LIBSO) $(SHAREDFLAGS) $(LM)	 

$(TARGET3):
	$(CC) $(CFLAGS) -c -o $(OBJMAIN3) $(MAIN3) $(LM)
	$(CC) $(CFLAGS) -o $(TARGET3) $(OBJMAIN3) $(LM) $(LDL)
clear:
	rm -f *.o 

clean:
	rm -f $(TARGET) $(TARGET2) $(TARGET3)  *.o *.so
