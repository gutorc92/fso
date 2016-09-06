#ifndef OPERATIONS_H
#define OPERATIONS_H

int print_matrix(int **p, int columns, int rows);
int** create_matrix(int columns, int rows);
int free_matrix(int **p, int columns, int rows);
int insert_matrix(int **p, int columns, int rows);
int read_matrix(int **p, int columns, int rows,const char *file);

#endif
