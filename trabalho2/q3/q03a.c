/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 *
 * Enunciado:
 * Implemente o programa q03a que realize a multiplicação de matrizes de forma
 * sequencial, ou seja, execute todas as operações em uma única thread (a thread
 * principal do processo).
 *
 * As observações desse programa em resposta ao enunciado estão no arquivo
 * README.md nessa mesma pasta.
 */
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(void) {

	int columns = 3, rows = 3;
	int **p = NULL;
	int **x = NULL;
	int **c = NULL; 
	p = create_matrix(columns,rows);

	if(!p){
		perror("Matrix p not created correctly\n");
		return -1;
	}
	x = create_matrix(columns,rows);
	if(!x){
		perror("Matrix p not created correctly\n");
		return -1;
	}
	c = create_matrix(columns,rows);
	if(!c){
		perror("Matrix p not created correctly\n");
		return -1;
	}
	read_matrix(p,columns,rows,"matrix1");
	read_matrix(x,columns,rows,"matrix2");

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int sum = 0;
			for(int k = 0; k < 3; k++){
				sum += p[i][k] * x[k][j];
			}
			c[i][j] = sum;
		}
	}
	printf("Matrix from file 1\n");
	print_matrix(p,columns,rows);
	printf("Matrix from file 2\n");
	print_matrix(x,columns,rows);
	printf("Result matrix\n");
	print_matrix(c,columns,rows);

	free_matrix(p,columns,rows);
	free_matrix(x,columns,rows);
	free_matrix(c,columns,rows);
    return 0;
}
