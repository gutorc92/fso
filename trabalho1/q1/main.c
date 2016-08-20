#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "types.h"
#include "operations.h"
#include "in.h"

int main(int argc, char * argv[]){
	Triangle t;
	read_triangle(&t);
	print_triangle(&t);
	if(triangle_exists(&t)){
		print_triangle_info(&t);
	}else{
		printf("Os pontos fornecidos não formam um triângulo");
	}
	return 0;
}
