#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall -Werror -O2

#Compile
CC=gcc

#Name of the executable file
TARGET=q03a

#Files
PROG1 = q03a.c
OBJ = q03a.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f $(TARGET) *.o
