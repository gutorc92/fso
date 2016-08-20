#
# Makefile 
#

#Flags used to compile files
CFLAGS = -g -Wall -Werror -O2 -lm 

#Compile
CC=gcc

#Deps
DEPS=types.h operations.h in.h 

#Name of the executable file
TARGET=prog

#Files
PROG1 = main.c operations.c in.c
OBJ = main.o operations.o in.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

clean:
	rm -f $(TARGET) *.o
