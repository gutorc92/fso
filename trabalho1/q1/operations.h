#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "types.h"
#include <math.h>

int triangle_exists(Triangle* t); 
double triangle_perimeter(Triangle* t);
double triangle_area(Triangle* t);
double distancebtdots(Dot *a, Dot* b);
#endif
