#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

/*	
 *  Function to print the elements of poiter of pointer.
 *  It need the dimensions of the pointer.
 *  
 */
int print_matrix(int **p, int columns, int rows){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(j + 1 < columns){
				printf("%d ",p[i][j]);
			}else{
				printf("%d",p[i][j]);
			}
			
		}
		printf("\n");
	}
	return 1;

}

/*	
 *  It creates a pointer of pointer with dimensions
 *  columns and rows.
 *  
 */
int** create_matrix(int columns, int rows){
	int **p = (int **) malloc(sizeof(int *) * rows);
	if(!p){
		perror("It has a problem to allocate the pointer p\n");
		return 0;
	}
	for(int i = 0; i < rows; i++){
		int size = sizeof(int) * columns;
		p[i] = (int *)malloc(size );
		if(!p[i]){
			perror("It has a problem to allocate the pointer p\n");
			fprintf(stderr,"The problem is on the pointer p[%d]\n",i);
			return 0;
		}
	}
	return p;
}

/*	
 *  Desalocate a pointer of pointer
 *  
 *  
 */
int free_matrix(int **p, int columns, int rows){
	for(int i = 0; i < rows; i++){
		free(p[i]);	
	}
	free(p);
	return 1;
}

/*	
 *  It fills a pointer of pointer from default
 *  input.
 *  
 */
int insert_matrix(int **p, int columns, int rows){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("Entre com o elemento: %d %d: \n",i,j);
			scanf("%d",&p[i][j]);
			printf("\n");
		}
	}
	return 1;
}

/*	
 *  It fills a pointer of pointer from a file.
 *  
 */
int read_matrix(int **p, int columns, int rows,const char *file){
	FILE *fp;
	fp = fopen(file, "r");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(fp,"%d",&p[i][j]);
		}
	}
	fclose(fp);
	return 1;
}

int** read_matrix_from_file(const char *file,int * prows,int * pcolumns){
	FILE *fp;
	int rows = 0,columns = 0;
	fp = fopen(file, "r");
	fscanf(fp,"%d",&rows);
	fscanf(fp,"%d",&columns);
	if(rows == 0 && columns == 0){
		return NULL;
	}
	*prows = rows; *pcolumns = columns;
//printf("rows %d columns %d\n",rows,columns);
	int **p = create_matrix(columns,rows);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(fp,"%d",&p[i][j]);
		}
	}
	fclose(fp);
	return p;
}

int check_args(int *argv, char * argc[]){
	if(*argv < 4){
		perror("You should give the two files where the matrixs are.\n");
		return 1;
	}
	FILE *fp;
	int j = 0;
	for(int i = 2; i < *argv; i++){
		fp = fopen(argc[i],"r");
		if (fp!=NULL){ 
			fclose (fp);
			j++;
		}
	}
	if(j != 2){
		perror("The programa cannot find the files where the matrixs should be..\n");
		return 1;
	}
	return 0;
}
