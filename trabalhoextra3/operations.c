#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int position(char * values, char * element){
	char * result = strchr(values,element);
	if(result != NULL){
		return result - values;
	}
	return -1;
}

int next_space(char * search, int begin){
	char space = " ";
	char * result = strchr(search+begin,space);
	if(result != NULL){
		return result - search;
	}
	return -1;
}

int read_request(request *r,char buffer){
	return 0;
}

regex_t * create_regex(const char * regex){
	regex_t * re = malloc(sizeof(regex_t));
	if(re == NULL){
		return NULL;
	}
	int result = regcomp(re,regex,0);
	if(result){
		fprintf(stderr,"You have pass a wrong regex format\n");
		return NULL;
	}
	return re;
}

