/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stddef.h>
//do stuff

int check_argv(int * argv){
	if(*(argv) < 4){
		perror("It has to have 3 arguments");
		return 1;
	}
	return 0;
}

int print_args(char * directory, char * search, int * num){
	printf("Directory %s\n",directory);
	printf("Search %s\n",search);
	printf("Lines %d\n",*(num));
	return 0;	
}


int read_args(char * argc[], char ** directory, char ** search, int * num){
	int len = strlen(argc[1]);
	*directory = malloc(sizeof(char) * len);
	if(*directory == NULL){
		return 1;
	}
	strcpy(*directory,argc[1]);

	len = strlen(argc[2]);
	*search = malloc(sizeof(char) * len);
	if(*search == NULL){
		return 1;
	}
	strcpy(*search,argc[2]);

	*(num) = atoi(argc[3]);

	return 0;
}

<<<<<<< HEAD
=======
int print_file(char * file, int *nr_file){
    int nr = *(nr_file);
    nr++;
    printf("\t%d. %s --\n",nr,file);
    FILE * fp;
    fp = fopen(file, "r");
    if(fp != NULL){
        //printf("Chegou aqui\n");
        char buffer[30];
        fgets(buffer,30,fp);
        printf("\t  %s\n",buffer);
        fclose(fp);
    }
    
    return 1;
}



>>>>>>> t4q2
int child_dir(char * name, char * search, int * nr_printed_lines,int * nr_lines){
	if(*(nr_printed_lines) >= *(nr_lines)){
		return 1;
	}

    char name2[1024];
    //printf("Dir: %s\n",name);
	DIR *dp;
	struct dirent *ep;
	char * found = NULL;
	dp = opendir(name);
	if(dp != NULL){
		while((ep = readdir(dp))){
            strcpy(name2,name);
			if(ep->d_type == DT_REG){
				//printf("It is a file %s\n",ep->d_name);
				found = strstr(ep->d_name,search);
				if(found != NULL){
					if(*(nr_printed_lines) <= *(nr_lines)){
						//printf("\tIt matches a file\n");
						strcat(name2,"/");
                        print_file(strcat(name2,ep->d_name),nr_printed_lines);                   
						(*nr_printed_lines)++;
                        //printf("\tPrinted lines: %d\n",*(nr_printed_lines));
						//printf("\tNr lines: %d\n",*(nr_lines));

					}else{
						(void)closedir(dp);
						return 0;
					}
				}
			}else if(ep->d_type == DT_DIR){
				//printf("It is a directory %s\n",ep->d_name);
				//printf("\tResult comp: %d\n",strcmp(ep->d_name,".") == 0 || strcmp(ep->d_name,"..") == 0);
				if(!(strcmp(ep->d_name,".") == 0 || strcmp(ep->d_name,"..") == 0)){
					//printf("\tIt will scan the dir directory %s\n",ep->d_name);
                    strcat(name2,"/");
					child_dir(strcat(name2,ep->d_name),search,nr_printed_lines,nr_lines);
				}
			}
		}
		(void)closedir(dp);
	}else{
		perror("It cannot open the directory\n");
	}
	return 0;
}

int main(int argv, char * argc[]) {

	if(check_argv(&argv)){
		return 1;
	}

	char *directory = NULL, * search = NULL;
	int num_lines = 0, nr_lines_printed = 0;
	if(read_args(argc,&directory,&search, &num_lines)){
		return 1;
	}
	//print_args(directory,search,&num_lines);
    printf("Resultado de buscador -- \"%s\" na pasta %s\n",search,directory); 
	child_dir(directory,search,&nr_lines_printed,&num_lines);
	free(directory);
	free(search);
	return 0;
}
