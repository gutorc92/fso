/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "types.h"
#include "operations.h"
#include "in.h"

int main(int argc, char * argv[]){
	Triangle t;
	read_triangle(&t);
	print_triangle(&t);
	if(triangle_exists(&t)){
		print_triangle_info(&t);
	}else{
		printf("Os pontos fornecidos não formam um triângulo\n");
	}
	return 0;
}
