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

int main(int argv, char * argc[]) {

	if(check_args(&argv,argc)){
		printf("Check stderr for more informations\n");
		return -1;
	}	
	int columns_p = 0, rows_p = 0;
	int columns_x = 0, rows_x = 0;
	int **p = NULL; int **x = NULL; int **c = NULL;
	 
	
	
	p = read_matrix_from_file(argc[1],&rows_p,&columns_p);

	if(!p){
		perror("Matrix p not created correctly\n");
		return -1;
	}
	x = read_matrix_from_file(argc[2],&rows_x,&columns_x);
	if(!x){
		perror("Matrix x not created correctly\n");
		return -1;
	}
	if(columns_p != rows_x){
		perror("Columns of p are different of x'rows\n");
		fprintf(stderr, "The columns of p are: %d and rows of x are %d\n",columns_p,rows_x);
		return -1;
	}
	c = create_matrix(columns_x,rows_p);
	if(!c){
		perror("Matrix c not created correctly\n");
		return -1;
	}
	//read_matrix(p,columns,rows,"matrix1");
	//read_matrix(x,columns,rows,"matrix2");

	for(int i = 0; i < rows_p; i++){
		for(int j = 0; j < columns_x; j++){
			int sum = 0;
			for(int k = 0; k < rows_x; k++){
				sum += p[i][k] * x[k][j];
			}
			c[i][j] = sum;
		}
	}
	/*
	printf("Matrix from file 1\n");
	print_matrix(p,columns_p,rows_p);
	printf("Matrix from file 2\n");
	print_matrix(x,columns_x,rows_x);
	printf("Result matrix\n");
	*/
	print_matrix(c,columns_x,rows_p);

	free_matrix(p,columns_p,rows_p);
	free_matrix(x,columns_x,rows_x);
	free_matrix(c,columns_x,rows_p);
    return 0;
}
