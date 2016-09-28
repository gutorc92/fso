#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <sys/time.h>
#include <sys/types.h>
#include <regex.h>

static const char GET[] = "GET";

struct _request{
	char * method;
	char * params;
	char * protocol;
	char * others;
};

typedef struct _request request;

struct _response{
	char * code;
	char * protocol;
	char * others;
};

typedef struct _response response;

int position(char * values, char * element);

int next_space(char * str, int begin);

int read_request(request *r,char * buffer);

regex_t * create_regex(const char * regex);

char * create_request_param(int numchars);

int print_request(request *r);

int check_request(request *r);

int check_file(char * file);

response * create_response();
response * resolve_get_request(request *r);

#endif
