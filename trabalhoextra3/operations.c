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

void read_params_request(int position, int numchars, char * word, request *r){
	if(position == 1){
		strncpy(r->method,word,numchars);
	}else if(position == 2){
		strncpy(r->params,word,numchars);
	}else if(position == 3){
		strncpy(r->protocol,word,numchars);
	}
}

int read_request(request *r,char * buffer){
	const char regex[] = "(\\S+)\\s(\\S+)\\s(\\S+)";
	regex_t * re = create_regex(&regex);
	regmatch_t matches[4];
	char word[81];
	int numchars = 0;
	int result = regexec(re,buffer,4,matches,0);
	if(!result){
printf("Match");
		for(int i = 0; i < 4; i++){
			printf("Comeco: %d\n",(int)matches[i].rm_so);
			if((int)matches[i].rm_so < 0) break;
			numchars = (int)matches[i].rm_eo - (int)matches[i].rm_so;
			strncpy(word,buffer+matches[i].rm_so,numchars);
			read_params_request(i,numchars,buffer+matches[i].rm_so,r);	
            word[numchars] = '\0';
			printf("From %d to %d (%s)\n",(int)matches[i].rm_so,
					(int)matches[i].rm_eo,word);
			
		}
	}else{
		fprintf(stderr,"It does not match anything\n");
	}
	free(re);
	return 0;
}

regex_t * create_regex(const char * regex){
	regex_t * re = malloc(sizeof(regex_t));
	if(re == NULL){
		return NULL;
	}
	int result = regcomp(re,regex,REG_EXTENDED);
	if(result){
		fprintf(stderr,"You have pass a wrong regex format\n");
		return NULL;
	}
	return re;
}

