#ifndef TYPES_H
#define TYPES_H

struct _Dot{
	double x;
	double y;
};
typedef struct _Dot Dot;

struct _Triangle{
	Dot first;
	Dot second;
	Dot third;	
};
typedef struct _Triangle Triangle;
 
#endif
