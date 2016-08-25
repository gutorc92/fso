#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "types.h"
#include <math.h>

int order(Command* c, Vector * v);
int print_vector(Vector* v);
int has_command(Command * c, char * argv[]);
int init(Vector* v, int size);
int swap(int * i, int * j);
int dorder(Vector *v);
int rorder(Vector *v);

#endif
