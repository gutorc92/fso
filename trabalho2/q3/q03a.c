/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * exit() call
 */
void abort_program(void);

/**
 * Write each space in matrix
 */
int load_matriz(int dimension_line, int dimension_col,
    int matrix[dimension_line][dimension_col]);

int main() {
  int dimension_col, dimension_line;

  int success_read = -1;

  printf("N. of lines: ");
  success_read = scanf("%d", &dimension_line);

  if(success_read) {
    printf("N. of columns: ");
    success_read = scanf("%d", &dimension_col);
  } else {
    abort_program();
  }

  // To multiply matrices is needed number of columns
  // equals to lines of second matrix
  int first_matrix [dimension_col][dimension_line];
  int second_matrix [dimension_line][dimension_col];

  if(success_read) {
    success_read = load_matriz(dimension_col, dimension_line, first_matrix);
  } else {
    abort_program();
  }

  if(success_read) {
    load_matriz(dimension_line, dimension_col, second_matrix);
  } else {
    abort_program();
  }

  return 0;
}

int load_matriz(int dimension_line, int dimension_col,
     int matrix[dimension_line][dimension_col]) {

  printf("Fill this matrix[%d][%d]\n", dimension_line, dimension_col);

  int success_read = 1;
  int i, j;

  for(i = 0; i < dimension_col; i++) {
    for(j = 0; j < dimension_line; j++) {
      printf("A[%d][%d] = ", i, j);
      if(success_read) {
        success_read = scanf("%d", &matrix[i][j]);
      } else {
        abort_program();
      }
    }
  }

  return success_read;
}

void abort_program(void) {
  printf("Some failure on executation...");
  exit(EXIT_FAILURE);
}
