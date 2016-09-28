#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99
CURRENT_DIR = $(shell pwd)
SHAREDFLAGS = -lprimo -lm -L. -Wl,-rpath,$(CURRENT_DIR)

#Compile
CC=gcc

TARGET=prog
TARGET2=prog2

#Files
PROG1 = main.c
OBJ1 = main.o

DEPS= libprimo.h
LIB= libprimo.c
OBJL= libprimo.o
OBJL2= libprimosh.o
SHARED=libprimo.so

all: $(TARGET) $(TARGET2)  clear

$(TARGET):
	$(CC) $(CFLAGS) -c -o libprimo.o libprimo.c
	$(CC) $(CFLAGS) -c -o main.o main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.o libprimo.o -lm
	rm *.o

$(TARGET2):
	$(CC) -c -std=c99 -fPIC libprimo.c
	$(CC) -shared -fPIC -o libprimo.so libprimo.o
	$(CC) $(CFLAGS) -o $(TARGET2) main.c libprimo.o -lprimo $(SHAREDFLAGS)	 

clear:
	rm -f *.o 

clean:
	rm -f $(TARGET) $(TARGET2)  *.o *.so
