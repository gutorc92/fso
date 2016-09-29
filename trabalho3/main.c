/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libprimo.h"

int main() {
	for(int count = 0; count < 5; count++) {
		int prime = gera_primo();
		printf("Founded prime>> %d\n", prime);
		sleep(1);
	}
	return 0;
}
