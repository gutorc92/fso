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

/**
 * Recebe nome_arquivo AAAAMMDDHHmm
 */
int main(int argc, char * argv[]) {
  char *file_name = argv[1];
  char *input_date = argv[2];

  struct state file_info;
  int read_status;

  read_status = stat(file_name, &file_info);

  if(read_status) {
    printf("%w\n", &file_info);
  }
}
