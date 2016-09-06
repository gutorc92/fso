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

struct plus_params{
	int *w;
	int *x;
	int i;
	int j;
};
void* plus_matrix(void * arg){
	struct plus_params * params = (struct plus_params *)arg;
	if(params->x[params->i] > params->x[params->j]){
		params->w[params->j] = 0;
	}else{
		params->w[params->i] = 0;
	}
	return NULL;
}

int main(void) {
	int numbers = 4;
	int *x = malloc(sizeof(int) * numbers);
	int *w = malloc(sizeof(int) * numbers);
	w[0] = 1; w[1] = 1; w[2] = 1; w[3] = 1;
	x[0] = 3; x[1] = 1; x[2] = 7; x[3] = 4;
	int nr_threds = (numbers*(numbers - 1))/2;
	pthread_t *thread_ids = malloc(sizeof(pthread_t)*nr_threds);
	int id = 0;
	for(int i = 0; i < numbers-1; i++){
		for(int j = i+1; j < numbers; j++){
			struct plus_params params;
			params.w = w; 
			params.x = x; 
			params.i = i; 
			params.j = j; 
			pthread_create(&thread_ids[id], NULL, &plus_matrix, &params);
			pthread_join(thread_ids[id], NULL);
			id++;
		}
	}
	for(int i = 0; i < numbers; i++){
		printf("%d ",w[i]);
	}
	free(w);
	free(x);
    return 0;
}
