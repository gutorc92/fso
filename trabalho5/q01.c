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
int count_lines_thread[10];
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
	char text[threads_number];
	for(int i = 0; i < p->nr_outputs; i++){
		text[i] = p->caracter;
	}
	text[p->nr_outputs] = '\0';

	p->nr_outputs--;
	// waiting Ctrl + C
	while(keep_looping) {
		printf("%s\n", text);
		count_lines_thread[p->nr_outputs]++;
		pthread_mutex_lock(&print_mutex);
  	usleep(500000);
		pthread_mutex_unlock(&print_mutex);
	}
	return NULL;
}

int main(int argv,char *argc[]) {
	threads_number = atoi(argc[1]);
	// Thread number should be between (0, 10)
	if(threads_number > 10 || threads_number <= 0) {
		printf("Número de threads inválido\n");
		exit(EXIT_FAILURE);
	}

	// wait a SIGINT to run handle_function
	signal(SIGINT, handler);

	thread_ids = malloc(sizeof(pthread_t) * 10);
	params * parms = malloc(sizeof(params) * 10);

	for(int i = 0; i < threads_number; i++) {
	  params * p = &parms[i];
	  p->nr_outputs = i - 1;
		// ASCII value of initial letter (a)
	  p->caracter = ASCII_A + i;
	  pthread_create(&thread_ids[i], NULL, &print, p);
	}

	// waiting ctrl+C
	while(keep_looping);
	return 0;
}
