#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall -std=c99 

#Compile
CC=gcc

TARGET=client
TARGET2=server
TARGET3=test

#Files
PROG1 = client.c 
OBJ1 = client.o

PROG2 = server.c
OBJ2 = server.o

PROG3 = test.c
OBJ3 = test.o

DEPS= operations.h
LIB= operations.c
OBJL= operations.o




all: $(TARGET) $(TARGET2)  clear

$(OBJL) : $(LIB) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ1) : $(PROG1)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ1) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

$(OBJ2) :  $(PROG2)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET2): $(OBJ2) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

$(OBJ3) :  $(PROG3)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET3): $(OBJ3) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm 
clear:
	rm -f *.o

clean:
	rm -f $(TARGET) $(TARGET2) $(TARGET3) *.o
