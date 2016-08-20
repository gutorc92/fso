#include "in.h"
#include "types.h"
#include <stdio.h>
#include <math.h>
#include "operations.h"

int read_dot(Dot* d){
	printf("Digite a coordenada x do ponto:\n");
	int result = scanf("%lf",&d->x);
	printf("Digite a coordenada y do ponto:\n");
	result = scanf("%lf",&d->y);

	return result;
}
int print_dot(Dot* d){
	printf("O ponto tem coordenadas x: %5.2lf e y: %5.2lf\n",d->x,d->y);
	return 1;
} 
int read_triangle(Triangle* t){
	printf("Você tem que digitar os três pontos do triângulo\n");
	printf("O primeiro ponto: \n");
	read_dot(&t->first);
	printf("O segundo ponto: \n");
	read_dot(&t->second);
	printf("O terceiro ponto: \n");
	read_dot(&t->third);

	return 1;
}

int print_triangle(Triangle* t){
	printf("Imprimindo os três pontos do triângulo\n");
	printf("O primeiro ponto: \n");
	print_dot(&t->first);
	printf("O segundo ponto: \n");
	print_dot(&t->second);
	printf("O terceiro ponto: \n");
	print_dot(&t->third);

	return 1;
}
int print_triangle_info(Triangle* t){
	printf("O perímetro do triângulo: %5.2lf\n",triangle_perimeter(t));
	printf("A área do triângulo: %5.2lf\n",triangle_area(t));
	return 1;
}

