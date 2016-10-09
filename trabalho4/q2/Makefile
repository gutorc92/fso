#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99 -D_BSD_SOURCE 

#Compile
CC=gcc

TARGET = prog


$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) main.c 

clear:
	rm -f *.o

clean:
	rm -f $(TARGET) *.o
