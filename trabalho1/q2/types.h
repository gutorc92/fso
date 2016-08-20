#ifndef TYPES_H
#define TYPES_H

struct _Command{
	char c;
};
typedef struct _Command Command;

struct _Vector{
	int * data;
	int size;
};
typedef struct _Vector Vector;
 
#endif
