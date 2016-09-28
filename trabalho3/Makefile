#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99 

#Compile
CC=gcc

TARGET=prog

#Files
PROG1 = main.c 
OBJ1 = main.o 

DEPS= libprimo.h
LIB= libprimo.c
OBJL= libprimo.o

all: $(TARGET)  clear

$(OBJL) : $(LIB) $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJ1) $(OBJL)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread

$(OBJ1) :  $(PROG1)
	$(CC) $(CFLAGS) -c -o $@ $<

clear:
	rm -f *.o

clean:
	rm -f $(TARGET)  *.o
