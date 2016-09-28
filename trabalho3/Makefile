#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99
CURRENT_DIR = $(shell pwd)
SHAREDFLAGS = -lm -L. lprimo -WL,-rpath,$(CURRENT_DIR)

#Compile
CC=gcc

TARGET=prog
TARGET2=pro2

#Files
PROG1 = main.c
OBJ1 = main.o

DEPS= libprimo.h
LIB= libprimo.c
OBJL= libprimo.o
OBJL2= libprimosh.o
SHARED=libprimo.so

all: $(TARGET)  clear

$(OBJL) : $(LIB) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ1) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ 

$(OBJ1) :  $(PROG1)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJL2) : $(LIB)
	$(CC) $(CFLAGS) -c -fPIC $@ $<

$(SHARED):
	$(CC) -shared -fPIC -o $(SHARED) $(OBJL2)

$(TARGET2): $(OBJ1) $(SHARED)
	$(CC) $(CFLAGS) $(SHAREDFLAGS) -o $@ $^

clear:
	rm -f *.o

clean:
	rm -f $(TARGET)  *.o
