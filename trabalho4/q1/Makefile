#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall --std=c99

#Compile
CC=gcc

TARGET = prog


$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET) *.o
