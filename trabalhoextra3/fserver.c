#include "fserver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void lr(const char *msg){
	fprintf(stderr,"ERROR, %s\n",msg);
}

void error(const char *msg){
    perror(msg);
    exit(1);
}

int check_args(int * argc){
	if(*argc < 2){
		lr("no port provided");
		return 1;
	}
	return 0;
}
