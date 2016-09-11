/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 *
 * Comparação de inteiros usando threads.
 * Dado 2 arrays de mesmo tamanho X e W, um com uma sequencia de números
 * e o outro com todos espaços em 1, qual seria o maior numero no primeiro?
 * Compare os números de X, colocando um 0 na matriz W para qual número em X
 * é menor na comparação feita.
 *
 * Enunciado:
 * Entrada e saída. O programa a ser implementado deverá receber entradas por
 * meio de parâmetros de linha de comando. Considerando que o seu executável
 * tem nome q02, espera-se uma entrada da seguinte maneira:
 * -./q02 n x[0] x[1] x[2] ... x[n-1]
 * -./nome_executável n_inteiros inteiro_0 inteiro_1 inteiro_2 ... inteiro_n-1
 * -Considere esquema de programação defensiva e limite o seu programa para
 *  receber sequências de inteiro de até 100 elementos.
 * -Requisitos funcionais que o programa deverá atender:
 * 	-Imprimir o número de elementos da sequência de inteiros, a sequência de
 * 	-inteiros x e os valores do array w.
 * 	-A atividade realizada pela thread Tij na Etapa2.
 * 	-Os valores do array w após a Etapa 2.
 * 	-O valor do máximo da sequência e sua posição.
 *
 * As observações desse programa em resposta ao enunciado estão no arquivo
 * README.md nessa mesma pasta.
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LIMIT 100

struct comparator {
	// array with numbers
	int *W;
	// array with result of comparations
	int *X;
	// current position of first number
	int i;
	// second number compared with first
	int j;
};

void* compare(void * arg);
int * init_array(int sequence_size, char * argv[]);
int * init_filled_with_one(int sequence_size);
void validate_arguments(int array_size);
void print_current_status(int * X, int * W, int array_size);

int main(int argc, char * argv[]) {

	// first argument must be size of array
	int array_size = atoi(argv[1]);

	validate_arguments(array_size);

	printf("Number of input values = %d\n", array_size);

	int *X = init_array(array_size, argv);
	int *W = init_filled_with_one(array_size);

	printf("Input values X = ");

	for(int i = 0; i < array_size; i++) {
		printf("%d ",X[i]);
	}
	printf("\n");

	printf("After initialization W = ");
	for(int i = 0; i < array_size; i++) {
		printf("%d ",W[i]);
	}
	printf("\n");

	for(int i = 0; i < array_size-1; i++) {
		// i+1 para que nao se compare com ele mesmo
		for(int j = i+1; j < array_size; j++) {
			// cria um novo comparador para rodar na thread
			struct comparator params;
			params.W = W;
			params.X = X;
			params.i = i;
			params.j = j;

			compare(&params);
		}
	}

	print_current_status(X, W, array_size);
	printf("\n");

	free(W);
	free(X);

  return 0;
}


void* compare(void * arg) {
	struct comparator * current_comparator = (struct comparator *) arg;

	int index_i = current_comparator->i;
	int index_j = current_comparator->j;

	if(current_comparator->X[index_i] > current_comparator->X[index_j]) {
		printf("Thread T(%d, %d) compares x[%d] and x[%d], and writes 0 into w[%d]\n", index_i, index_j, index_i, index_j, index_j);
		current_comparator->W[index_j] = 0;
	} else {
		current_comparator->W[index_i] = 0;
	}

	return NULL;
}

/**
 * This func initiates the W array with passed sequence
 */
int * init_array(int sequence_size, char * argv[]) {
	int * sequence = malloc(sizeof(int) * sequence_size);

	for(int count = 0; count < sequence_size; count++) {
		sequence[count] = atoi(argv[count+2]);
	}

	return sequence;
}

/**
 * This func initiates the X array with 1
 */
int * init_filled_with_one(int sequence_size) {
	int * W = malloc(sizeof(int) * sequence_size);

	for(int count = 0; count < sequence_size; count++) {
		W[count] = 1;
	}

	return W;
}

void validate_arguments(int array_size) {
	if(array_size > ARRAY_LIMIT) {
		printf("Please enter with an max of 100 numbers\n");
		exit(EXIT_FAILURE);
	}

	if(array_size < 2 ) {
		printf("You need pass at least two arguments\n");
		exit(EXIT_FAILURE);
	}
}

void print_current_status(int * X, int * W, int array_size) {
	printf("After step 2\n");

	printf("W = ");
	for(int i = 0; i < array_size; i++) {
		printf("%d ", W[i]);
	}

	printf("\n");

	for(int i = 0; i < array_size; i++) {
		if(W[i] == 1) {
			printf("Maximum = %d\n", X[i]);
			printf("Location = %d\n", i);
		}
	}
}
