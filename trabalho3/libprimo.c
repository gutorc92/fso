#include "libprimo.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
/**
 * If prime returned 1
 */
int testa_primo(int number) {
	// se um numero não é primo, entao existe um fator divisivel
	// abaixo de sua raiz quadrada
	int factor_compose = sqrt(number);
	if ((factor_compose % 2) == 0) {
		return 0;
	}

	for(int count = factor_compose; count > 1; count--) {
		if((number % count) == 0) {
			return 0;
		}
	}

	return 1;
}


int gera_primo() {
	srand(time(NULL));
	int prime = 0;

	do {
		int r = rand();
		if(r%2 != 0 && testa_primo(r)) {
			prime = r;
		}
	} while(prime==0);

	return prime;
}
