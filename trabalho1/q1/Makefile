#
# Makefile 
#

#Flags used to compile files
CPPFLAGS = -g -Wall 

#Compile
CXX=gcc

#Deps
DEPS=types.h operations.h in.h 
#Name of the executable file
TARGET=prog

#Files
PROG1 = main.c operations.c in.c
OBJ = main.o operations.o in.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $@ $^ -lm

clean:
	rm -f $(TARGET) *.o
