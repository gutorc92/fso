/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "operations.h"
#include <regex.h> 


int main(int argc, char *argv[]){
	
	const char regex[] = "(\\S+)\\s(\\S+)\\s(\\S+)";
	regex_t * re = create_regex(&regex);
	regmatch_t matches[10];
	char word[81];
	char text[] = "GET /gustavo/Documents/file.txt HTTP/1.0";
	int numchars = 0;
	int result = regexec(re,text,10,matches,0);
	if(!result){
		printf("Match");
		for(int i = 0; i < 10; i++){
			printf("Comeco: %d\n",(int)matches[i].rm_so);
			if((int)matches[i].rm_so < 0) break;
			numchars = (int)matches[i].rm_eo - (int)matches[i].rm_so;
			strncpy(word,text+matches[i].rm_so,numchars);
            word[numchars] = '\0';
			printf("From %d to %d (%s)\n",(int)matches[i].rm_so,
					(int)matches[i].rm_eo,word);
		}
	}else{
		printf("It does not match anything\n");
	}
	free(re);
	return 0; 
}
