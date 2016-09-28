#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libprimo.h"

int main() {
	for(int count = 0; count < 5; count++) {
		int prime = gera_primo();
		printf("Fucking prime>> %d\n", prime);
		sleep(1);
	}
	return 0;
}
