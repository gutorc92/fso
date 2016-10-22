/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 *
 * - O programa deverá receber como entradas o nome de um arquivo e uma string
 * numérica no formato AAAAMMDDHHmm em que A representa dígitos do ano, M, dígitos do
 * mês, D, dígitos do dia, H, dígitos hora e m, dígitos do minuto.
 * - Como saída, o programa deverá:
 * ▪ Gerar uma cópia de backup do arquivo (extensão .bkp) para efeito de validação das
 * alterações realizadas nos metadados de um arquivo.
 * ▪ Imprimir na tela quais são os metadados referentes ao horário da criação,
 * modificação e acesso do arquivo alvo.
 * ▪ Alterar os metadados do arquivo alvo de forma que as informações de horário sejam
 * substituídas pelo valor informado na string AAAAMMDDHHmm.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

#define STR_SIZE 64

/*
 * This method needs execution of prepare.sh before
 */
void get_creation_date(char *file_name) {
  char *command = "sudo debugfs -R \"stat $FILE_DIR\" $DIR_DISK | grep crtime\n";
  printf("Create date by debugfs:\n");
  system(command);
  printf("-----------------------\n");
}

void get_modification_date(struct stat *file_info) {
  time_t modificated_in;
  char timestr[STR_SIZE];

  modificated_in = file_info->st_mtime;
  strcpy(timestr, ctime(&modificated_in));

  printf("\nModified in %s\n",timestr);
}

void get_last_access_date(struct stat *file_info) {
  time_t modificated_in;
  char timestr[STR_SIZE];

  modificated_in = file_info->st_atime;
  strcpy(timestr, ctime(&modificated_in));

  printf("\nLast acess in %s\n",timestr);
}

void create_backup(char *file_name) {
  // The filename lenght limit in linux are 255, so with command cp
  // the maximum lenght is around 516
  char *command = malloc(sizeof(char)*516);
  char *backup_name = malloc(sizeof(char)*255);

  // create backup_name
  strcpy(backup_name, file_name);
  strcat(backup_name, ".bkp");

  strcat(command, "cp ");
  strcat(command, file_name);
  // flag to preserve metadata
  strcat(command, " -p ");
  strcat(command, backup_name);

  system(command);

  printf("The backup file was created.\n");
}

void change_time_metadata(char *file_name, char *date) {
  // Modify access and modify date
  char *basic_cmd = "touch -amt ";
  char *first_cmd = malloc(sizeof(char)*516);

  strcat(first_cmd, basic_cmd);
  strcat(first_cmd, date);
  strcat(first_cmd, " ");
  strcat(first_cmd, file_name);
  printf("First cmd is %s\n", first_cmd);

  // needs run two times to set atime and mtime
  system(first_cmd);
  system(first_cmd);

  // Now modify the creation date
  char *sec_cmd = malloc(sizeof(char)*516);
  // accepts data like sec

  // char *red_date = malloc(sizeof(char)*8);
  // strcpy(red_date, date);
  // red_date[8] = '\0';
  struct tm tm;
  time_t t;
  strptime(date, "%Y%m%d%H%M", &tm);
  t = mktime(&tm);

  char time_str[15];
  sprintf(time_str, "%d", (int) t);

  printf("Time: %s\n", time_str);

  strcat(sec_cmd, "sudo debugfs -w -R \"set_inode_field $FILE_DIR crtime ");
  strcat(sec_cmd, time_str);
  strcat(sec_cmd, "\" $DIR_DISK");

  system(sec_cmd);

  printf("Date of creation, access and modification was modified\n");
}

/**
 * Recebe nome_arquivo AAAAMMDDHHmm
 */
int main(int argc, char * argv[]) {
  char *file_name = argv[1];
  char *input_date = argv[2];

  create_backup(file_name);

  printf("File name: %s\n", file_name);
  printf("Date passed: %s\n\n", input_date);

  struct stat *file_info = malloc(sizeof(struct stat));
  int read_status;

  // if success, 0 was returned
  read_status = stat(file_name, file_info);

  if(read_status == 0) {
    get_creation_date(file_name);
    get_modification_date(file_info);
    get_last_access_date(file_info);
  } else {
    printf("Some error in stat read\n");
    return 0;
  }

  change_time_metadata(file_name, input_date);

  return 0;
}
