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
#include <string.h>
#include <unistd.h>

struct params{
	int nr_outputs;
	char caracter;
};
typedef struct params params;

void* print(void * arg){
	struct params * p = (struct params *)arg;
	for(int i = 0; i < p->nr_outputs; i++){
		printf("%c ",p->caracter);
        usleep(500000);
	}
	return NULL;
}

int main(int argv,char *argc[]) {
    pthread_t* thread_ids = malloc(sizeof(pthread_t) * 10);    	
    params * parms = malloc(sizeof(params) * 10);
    int c = 97;
    for(int i = 0; i < 10; i++){
        params * p = &parms[i];
        p->nr_outputs = i + 1;
        c =+ i;
        p->caracter = (char)c;
        pthread_create(&thread_ids[i], NULL, &print, p); 
    }
    return 0;
}
