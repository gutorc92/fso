#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <sys/time.h>
#include <sys/types.h>
#include <regex.h>

struct _request{
	char * method;
	char * params;
	char * protocol;
	char * others;
};

typedef struct _request request;

int position(char * values, char * element);

int next_space(char * str, int begin);

int read_request(request *r,char buffer);

regex_t * create_regex(const char * regex);

#endif
