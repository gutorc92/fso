#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99 

#Compile
CC=gcc

TARGET=b
TARGET2=a
TARGET3=c

#Files
PROG1 = q03b.c 
OBJ1 = q03b.o 

PROG2 = q03a.c 
OBJ2 = q03a.o 

PROG3 = q03c.c 
OBJ3 = q03c.o 

DEPS= operations.h
LIB= operations.c
OBJL= operations.o

all: $(TARGET) $(TARGET2) $(TARGET3) clear

$(OBJL) : $(LIB) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ1) : $(PROG1)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ1) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread

$(OBJ2) :  $(PROG2)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET2): $(OBJ2) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

$(OBJ3) : $(PROG3)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET3): $(OBJ3) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread

clear:
	rm -f *.o

clean:
	rm -f $(TARGET) $(TARGET2) $(TARGET3) *.o
