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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

struct plus_params{
	int **p;
	int **x;
	int column;
	int row;
	int max;
};
void* plus_matrix(void * arg){
	struct plus_params * params = (struct plus_params *)arg;
	int sum = 0;
	for(int i = 0; i < params->max; i++){
		sum += params->p[params->row][i] * params->x[i][params->column];
	}
	return (void *)sum;

}

int main(void) {

	int columns = 3, rows = 3;
	int **p = NULL;
	int **x = NULL;
	int **c = NULL;
	
	pthread_t * thread_ids = malloc(sizeof(pthread_t)*columns*rows);
	if(!thread_ids){
		perror("Thread nao criada corretamente\n");
		return 1;
	}
	p = create_matrix(columns,rows);
	if(!p){
		perror("Matrix p nao foi criada corretamente\n");
		return 1;
	}
	x = create_matrix(columns,rows);
	if(!x){
		perror("Matrix x nao foi criada corretamente\n");
		return 1;
	}
	c = create_matrix(columns,rows);
	if(!c){
		perror("Matrix c nao foi criada corretamente\n");
		return 1;
	}
	read_matrix(p,columns,rows,"matrix1");
	read_matrix(x,columns,rows,"matrix2");

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			struct plus_params params;
			params.p = p; 
			params.x = x; 
			params.row = i; 
			params.column = j; 
			params.max = 3;
			pthread_create(&thread_ids[i*rows+j], NULL, &plus_matrix, &params);
			pthread_join(thread_ids[i*rows+j], (void*) &c[i][j]);
		}
	}
	
	printf("Matrix lida do arquivo 1\n");
	print_matrix(p,columns,rows);
	printf("Matrix lida do arquivo 2\n");
	print_matrix(x,columns,rows);
	printf("Matrix resultado\n");
	print_matrix(c,columns,rows);

	free_matrix(p,columns,rows);
	free_matrix(x,columns,rows);
	free_matrix(c,columns,rows);
    return 0;
}