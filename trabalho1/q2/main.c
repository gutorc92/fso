#include<stdio.h>
#include<stdlib.h>
#include "types.h"
#include "operations.h"

int main(int argc, char * argv[]){
	/*
	printf("Numero de argumentos: %d\n",argc);
	for(int i = 2; i < argc; i++){
		printf("%s \n",argv[i]);
	}
	*/
	Command command;
	Vector vector;
	int i = 0;
	if(has_command(&command,argv)){
		i = 2;
	}
	//printf("i: %d\n",i);
	init(&vector,argc-i);
	for(int j = 0; j < argc - i;j++){
		vector.data[j] = atoi(argv[j + i]);
	}
	print_vector(&vector);
	order(&command,&vector);
	return 0;
}
