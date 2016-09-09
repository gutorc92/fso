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
#include <semaphore.h>
#include "operations.h"
#include <unistd.h>
#include <string.h>
struct plus_params{
	int **p;
	int **x;
	int **c;
	int column;
	int row;
	int max;
};
typedef struct plus_params plus_params;

void* plus_matrix(void * arg){
	struct plus_params * params = (struct plus_params *)arg;
	int sum = 0;
	for(int i = 0; i < params->max; i++){
		sum += params->p[params->row][i] * params->x[i][params->column];
	}
//printf("Sum: %d\n",sum);
	params->c[params->row][params->column] = sum;
	return NULL;
}

int main(int argv,char *argc[]) {
	gettimeofday(&start, NULL);
	int processors = sysconf(_SC_NPROCESSORS_ONLN);
//printf("p: %d\n",processors);
	if(check_args(&argv,argc)){
		printf("Check stderr for more informations\n");
		return -1;
	}	
	int columns_p = 0, rows_p = 0;
	int columns_x = 0, rows_x = 0;
	int **p = NULL; int **x = NULL; int **c = NULL;

	p = read_matrix_from_file(argc[2],&rows_p,&columns_p);
	if(!p){
		perror("Matrix p not created correctly\n");
		return -1;
	}
	x = read_matrix_from_file(argc[3],&rows_x,&columns_x);
	if(!x){
		perror("Matrix x not created correctly\n");
		return -1;
	}
	if(columns_p != rows_x){
		perror("Columns of p are different of x'rows\n");
		fprintf(stderr, "The columns of p are: %d and rows of x are %d\n",columns_p,rows_x);
		return -1;
	}
	pthread_t * thread_ids = malloc(sizeof(pthread_t)*columns_x*rows_p);
	plus_params * params = malloc(sizeof(plus_params)*columns_x*rows_p);
	if(!thread_ids){
		perror("Thread nao criada corretamente\n");
		return 1;
	}

	c = create_matrix(columns_x,rows_p);
	if(!c){
		perror("Matrix c not created correctly\n");
		return -1;
	}
	//read_matrix(p,columns,rows,"matrix1");
	//read_matrix(x,columns,rows,"matrix2");
	int count = 0; int nr_counts = 0;
	for(int i = 0; i < rows_p; i++){
		for(int j = 0; j < columns_x; j++){
			int id = i*rows_p+j;
			plus_params * param = &params[id];
			param->p = p; 
			param->x = x; 
			param->c = c;
			param->max = rows_x;
			param->row = i; 
			param->column = j; 
			if(count < processors){
				pthread_create(&thread_ids[id], NULL, &plus_matrix, param);
				count++;
			}
			if(count == processors){
				for(int i = 0; i < processors; i++){
					pthread_join(thread_ids[nr_counts*processors + i], NULL);
				}
				nr_counts++;
				count = 0;
			}	
		}
	}
/*
	for(int i = 0; i < rows_p; i++){
		for(int j = 0; j < columns_x; j++){
			pthread_join(thread_ids[i*rows_p+j], NULL);
//printf("%d ",r);
		}
	}
	
	printf("Matrix lida do arquivo 1\n");
	print_matrix(p,columns_p,rows_p);
	printf("Matrix lida do arquivo 2\n");
	print_matrix(x,columns_x,rows_x);
	printf("Matrix resultado\n");
	*/
	//print_matrix(c,columns_x,rows_p);
	if(strcmp(argc[1],"t") == 0){
		gettimeofday(&stop, NULL);
		printf("took %lu\n", stop.tv_usec - start.tv_usec);
	}else{
		print_matrix(c,columns_x,rows_p);
	}
	free_matrix(p,columns_p,rows_p);
	free_matrix(x,columns_x,rows_x);
	free_matrix(c,columns_x,rows_p);
	free(thread_ids);
    return 0;
}
