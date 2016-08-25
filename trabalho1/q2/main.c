#include<stdio.h>
#include<stdlib.h>
#include "types.h"
#include "operations.h"

int main(int argc, char * argv[]){
	Command command;
	Vector vector;

	int number_cmds = 0;

	if(argc == 1) {
		printf("Please, enter with numbers!\n");
		return 0;
	} else {
		if(has_command(&command,argv)) {
			number_cmds = 2;
		}
	}

	// vector_size is equals to difference between 
	// argc  without
	int vector_size = argc - number_cmds;

	init(&vector, vector_size);

	for(int j = 0; j < vector_size;j++) {
		vector.data[j] = atoi(argv[j + number_cmds]);
	}
	printf("Values passed: ");
	print_vector(&vector);

	printf("Values in order ");
	order(&command,&vector);

	return 0;
}
