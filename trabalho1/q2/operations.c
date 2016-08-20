#include "operations.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int order(Command* c, Vector * v){
//printf("Command %c",c->c);
	if(c->c == 'd'){
//printf("Vai ordernar\n");
		dorder(v);
	}else if(c->c == 'r'){
		rorder(v);
	}else{
		dorder(v);
	}
	print_vector(v);
	return 1;
}
int print_vector(Vector* v){
	for(int i = 0; i < v->size; i++){
		printf("%d ",v->data[i]);
	}
	printf("\n");
	return 1;
}
int has_command(Command * c, char * argv[]){
	char d = argv[1][0];
	char op = argv[1][1];
//printf("D: %c\n",d);
//printf("OP: %c\n",op);
	if(d == '-' && (op == 'r'|| op == 'd')){
		c->c = op;
		return 1;
	}else{
		c->c = 'd';
	}
	return 0;
}

int init(Vector* v, int size){
	v->data = (int *)malloc(sizeof(int) * size);
	v->size = size;
	return 1;
}
int swap(int * i, int * j){
	int * temp;
	temp = i;
	i = j;
	j = temp;
	return 1;
}

int dorder(Vector *v){
	int swapped = 0;
	while(1){
		swapped = 0;
		for(int i = 1; i <= v->size - 1; i++){
//printf("dorder %d \n", v->data[i - 1]);
			if(v->data[i - 1] > v->data[i]){
				int temp = v->data[i - 1];
//printf("%d \n", temp);
				v->data[i - 1] = v->data[i];
				v->data[i] = temp;
				//swap(&v->data[i - 1], &v->data[i]);
				swapped = 1;
			}
			
		}
		if(!swapped) break;
	}
	return 1;
}


int rorder(Vector *v){
	int swapped = 0;
	while(1){
		swapped = 0;
		for(int i = 1; i <= v->size - 1; i++){
//printf("dorder %d \n", v->data[i - 1]);
			if(v->data[i - 1] < v->data[i]){
				int temp = v->data[i - 1];
//printf("%d \n", temp);
				v->data[i - 1] = v->data[i];
				v->data[i] = temp;
				//swap(&v->data[i - 1], &v->data[i]);
				swapped = 1;
			}
			
		}
		if(!swapped) break;
	}
	return 1;
}
