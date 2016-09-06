#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99 

#Compile
CC=gcc

#Name of the executable file
TARGET=b
TARGET2=a

#Files
PROG1 = q03b.c 
OBJ1 = q03b.o 

PROG2 = q03a.c 
OBJ2 = q03a.o 

all: $(TARGET) $(TARGET2)

$(OBJ1) : $(PROG1)
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJ1)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread

$(OBJ2) : $(PROG2)
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread
clean:
	rm -f $(TARGET) $(TARGET2) *.o
