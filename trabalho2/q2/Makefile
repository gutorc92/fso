#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99 

#Compile
CC=gcc

#Name of the executable file
TARGET=main

#Files
PROG1 = q03b.c
OBJ = q03b.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread

clean:
	rm -f $(TARGET) *.o
