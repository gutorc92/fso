#
# Makefile 
#

#Flags used to compile files
CFLAGS = -g -Wall -std=c99 -Werror -O2 -lm

#Compile
CXX=gcc

#Deps
DEPS=types.h operations.h  
#Name of the executable file
TARGET=prog

#Files
PROG1 = main.c operations.c 
OBJ = main.o operations.o 

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f $(TARGET) *.o
