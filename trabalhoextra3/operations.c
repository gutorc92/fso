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

int check_file(char * file){
	FILE *fp;
	fp = fopen(file,"r");
	if(fp){
		return 0;
	}
	return 1;
}

response * create_response(){
	response * r = malloc(sizeof(response));
	if(r){
		r->code = malloc(sizeof(char) * 4);
		r->protocol = malloc(sizeof(char)*9);
		if(r->code && r->protocol){
			r->protocol = "HTTP/1.1";
			return r;
		}
	}
	return NULL;
}

response * resolve_get_request(request *r){
	response * res = create_response();
	
	if(check_file(r->params)){
		res->code = "200";
	}	
	return 1;
}

int check_request(request *r){
	if(strcmp(r->method,GET)){
		return 0;
	}
	return 1;
}

int print_request(request *r){
	if(r){
		printf("The method %s\n",r->method);
		printf("The params %s\n",r->params);
		printf("The protocol %s\n",r->protocol);
		return 0;
	}
	return 1;
}

char * create_request_param(int numchars){
	char * c = malloc(sizeof(char) * numchars);
	if(c == NULL){
		return NULL;
	}
	return c;
}
//TODO put return erros 
void read_params_request(int position, int numchars, char * word, request *r){
	numchars++;
	if(position == 1){
		r->method = create_request_param(numchars);
		if(r->method){
			strncpy(r->method,word,numchars);
			r->method[numchars--] = '\0';
		}
	}else if(position == 2){
		r->params = create_request_param(numchars); 
		if(r->params){
			 strncpy(r->params,word,numchars);
			r->params[numchars--] = '\0';
		}
	}else if(position == 3){
		r->protocol = create_request_param(numchars);
		if(r->protocol){
			strncpy(r->protocol,word,numchars);
			r->protocol[numchars--] = '\0';
		}
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
            word[numchars] = '\0';
			printf("From %d to %d (%s)\n",(int)matches[i].rm_so,
					(int)matches[i].rm_eo,word);
			read_params_request(i,numchars,buffer+matches[i].rm_so,r);	
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

