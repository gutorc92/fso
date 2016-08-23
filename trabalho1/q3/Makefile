#
# Makefile 
#

#Flags used to compile files
CFLAGS = -g -Wall -Werror -O2 

#Compile
CC=gcc

#Name of the executable file
TARGET=main

#Files
PROG1 = main.c
OBJ = main.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

clean:
	rm -f $(TARGET) *.o
