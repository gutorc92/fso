/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	double number1 = 7.3, number2;
	char s1[100], s2[100];

	double * dPtr;
	dPtr = &number1;

	printf("Ponteiro para dPtr: %lf\n", *dPtr);

	number2 = *dPtr;
	printf("Valor number2: %lf\n", number2);
	printf("Endereço de number1: %p\n", &number1);
	printf("Endereço armazenado em dPtr: %p\n", &(*dPtr));

	printf("\nEscreva um valor textual >> ");

	int success_read = scanf("%s", s1);

	if(success_read) {
		strcpy(s2, s1);
	} else {
		printf("Valor não pode ser lido e o aplicativo será encerrado\n");
		return 0;
	}

	printf("String 2 é %s\n", s2);

	strcat(s1, s2);

	printf("String juntas formam %s\n", s1);

	return 0;
}
