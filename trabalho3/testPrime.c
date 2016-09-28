#include <stdio.h>
#include <stdlib.h>

int main() {
	int number = 0;
	scanf("%d", &number);

	for(int i = 2; i < number; i++) {
		if((number % i) == 0) {
			printf("Found an factor>> %d", i);
			break;
		}
	}
	return 0;
}
