#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <sys/time.h>

struct timeval stop, start;



int print_matrix(int **p, int columns, int rows);
int** create_matrix(int columns, int rows);
int free_matrix(int **p, int columns, int rows);
int insert_matrix(int **p, int columns, int rows);
int read_matrix(int **p, int columns, int rows,const char *file);
int** read_matrix_from_file(const char *file,int *prows,int *pcolumns);
int check_args(int *argv, char * argc[]);
#endif
