#include "operations.h"
#include "types.h"
#include <stdio.h>
#include <math.h>

double distancebtdots(Dot *a, Dot *b){
	double x = pow((a->x - b->x),2);
	double y = pow((a->y - b->y),2);
	double result = sqrt(x + y);
	return result;
}

int triangle_exists(Triangle* t){
	double a = distancebtdots(&t->first,&t->second); 
	double b = distancebtdots(&t->first,&t->third);
	double c = distancebtdots(&t->second,&t->third);
	if( a < b + c && b < a + c && c < a + b){
		return 1;
	}
	return 0;
} 
double triangle_perimeter(Triangle* t){
	double a = distancebtdots(&t->first,&t->second); 
	double b = distancebtdots(&t->first,&t->third);
	double c = distancebtdots(&t->second,&t->third);
	return a + b + c;
}
double triangle_area(Triangle* t){
	double pri = (t->first.x * t->second.y) + (t->first.y * t->third.x) + (t->second.x * t->third.y);
	double sec = (t->third.x * t->second.y) + (t->first.x * t->third.y) + (t->second.x * t->first.y);
	double result = pri - sec;
	if(result < 0) result = result * (-1);
	return result/2;

}



