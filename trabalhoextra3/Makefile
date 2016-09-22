#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall  

#Compile
CC=gcc

TARGET=client
TARGET2=server

#Files
PROG1 = client.c 
OBJ1 = client.o

PROG2 = server.c
OBJ2 = server.o


all: $(TARGET) $(TARGET2)  clear

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

clear:
	rm -f *.o

clean:
	rm -f $(TARGET) $(TARGET2)  *.o
