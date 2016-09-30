/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <math.h>

int (*gera_primo)();

/**
 * Gera cinco números primos, um a cada segundo
 */
int main() {
	void* lib = dlopen("./libprimo.so", RTLD_LAZY);
	gera_primo = dlsym(lib,"gera_primo");

	for(int count = 0; count < 5; count++) {
		int prime = gera_primo();
		printf("Founded prime>> %d\n", prime);
		sleep(1);
	}
	return 0;
}
