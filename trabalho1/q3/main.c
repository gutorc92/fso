/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 * 	Phelipe Wener  - 120132893
 * 	Gustavo Coelho - 
 */
#include<stdio.h>
#include<stdlib.h>

int main() {
	double number1 = 7.3, number2;
//	char s1[100], s2[100];

	double * dPtr;
	dPtr = &number1;

	printf("Ponteiro para dPtr: %lf\n", *dPtr);

	number2 = *dPtr;
	printf("Valor number2: %lf\n", number2);
	printf("Endereço de number1: %p\n", &number1);
	printf("Endereço armazenado em dPtr: %p\n", &(*dPtr));

	return 0;
}
