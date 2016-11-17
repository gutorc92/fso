#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99 

#Compile
CC=gcc

TARGET = prog

#Files
PROG1 = q01.c 
OBJ1 = q01.o 


all: $(TARGET)  clear


$(OBJ1) : $(PROG1)
	$(CC) $(CFLAGS) -D _BSD_SOURCE -c -o $@ $<

$(TARGET): $(OBJ1) 
	$(CC) $(CFLAGS) -o $@ $^ -lm -lpthread

clear:
	rm -f *.o

clean:
	rm -f $(TARGET) $(TARGET2) $(TARGET3) *.o
