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
#include <signal.h>

struct params{
	int nr_outputs;
	int caracter;
};

typedef struct params params;

pthread_mutex_t print_mutex;
int count_lines_thread[10];
int keep_looping = 1;
pthread_t* thread_ids;
 
void handle(int dumpy){
	keep_looping = 0;
	printf("Encerrando aplicação.Aguardando finalização de threads\n"); 
	for(int i = 0; i < 10; i++){
		pthread_join(thread_ids[i], NULL);
    	}
	printf("Aplicação encerrada com sucesso!\n");
	for(int i = 0; i < 10; i++){
		printf("thread %d: %d\n", i+1,count_lines_thread[i]);
	}
}

void* print(void * arg){
	struct params * p = (struct params *)arg;
	char text[10];
	for(int i = 0; i < p->nr_outputs; i++){
		text[i] = p->caracter;
	}
	p->nr_outputs--;
	while(keep_looping){
		pthread_mutex_lock(&print_mutex);
		printf("%s\n",text);
		count_lines_thread[p->nr_outputs]++;
		pthread_mutex_unlock(&print_mutex);
        	usleep(500002);
	}
	return NULL;
}

int main(int argv,char *argc[]) {
    signal(SIGINT, handle);
    thread_ids = malloc(sizeof(pthread_t) * 10);    	
    params * parms = malloc(sizeof(params) * 10);
    int c = 97;
    for(int i = 0; i < 10; i++){
        params * p = &parms[i];
        p->nr_outputs = i + 1;
        p->caracter = c;
        c++;
        pthread_create(&thread_ids[i], NULL, &print, p); 
    }
    while(keep_looping);
    return 0;
}
