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

#define ASCII_A 97

struct params {
	int nr_outputs;
	int caracter;
};

typedef struct params params;

pthread_mutex_t print_mutex;
int *count_lines_thread;
int keep_looping = 1;
pthread_t* thread_ids;
int threads_number = 0;

void handler(int dumpy) {
	keep_looping = 0;

	printf("Encerrando aplicação.Aguardando finalização de threads\n");
	for(int i = 0; i < threads_number; i++) {
		pthread_join(thread_ids[i], NULL);
	}

	printf("Aplicação encerrada com sucesso!\n");
	for(int i = 0; i < threads_number; i++) {
		printf("thread %d: %d\n", i+1, count_lines_thread[i]);
	}
}

void* print(void * arg){
	struct params * p = (struct params *)arg;
	char * text = malloc(sizeof(char) * p->nr_outputs);
    if(text == NULL){
        fprintf(stderr,"Can allocate vetor text for thread %d\n",p->nr_outputs);
    }
	for(int i = 0; i < p->nr_outputs; i++){
		text[i] = p->caracter;
	}

	// waiting Ctrl + C
	while(keep_looping) {
		pthread_mutex_lock(&print_mutex);
		printf("%s\n", text);
		pthread_mutex_unlock(&print_mutex);
		count_lines_thread[p->nr_outputs-1]++;
  	usleep(500000);
	}
    free(text);
	return NULL;
}

int main(int argv,char *argc[]) {
    if(argv != 2){
		printf("Número de parametros inválido\n");
		exit(EXIT_FAILURE);
    }
	threads_number = atoi(argc[1]);
	// Thread number should be between (0, 10)
	if(threads_number > 10 || threads_number <= 0) {
		printf("Número de threads inválido\n");
		exit(EXIT_FAILURE);
	}

	// wait a SIGINT to run handle_function
	signal(SIGINT, handler);

	count_lines_thread = malloc(sizeof(int) * threads_number);
    if(count_lines_thread == NULL){
        fprintf(stderr,"The vector count_lines_thread could not be allocated"); 
        return 1;
    }
	thread_ids = malloc(sizeof(pthread_t) * threads_number);
    if(thread_ids == NULL){
        fprintf(stderr,"The vector thread_ids could not be allocated"); 
        return 1;
    }
	params * parms = malloc(sizeof(params) * threads_number);
    if(parms == NULL){
        fprintf(stderr,"The vector params could not be allocated"); 
        return 1;
    }

	for(int i = 0; i < threads_number; i++) {
	  params * p = &parms[i];
	  p->nr_outputs = i+1;
		// ASCII value of initial letter (a)
		p->caracter = ASCII_A;
		p->caracter += i;
        pthread_create(&thread_ids[i], NULL, &print, p);
	}

	// waiting ctrl+C
	while(keep_looping);
	return 0;
}
