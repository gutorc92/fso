/*
 * Disciplina de FSO - 2016/2
 * Alunos:
 *      Phelipe Wener  - 120132893
 *      Gustavo Coelho - 110030559
 *
 * Enunciado:
 * Escreva um programa em C que implemente uma aplicação que simula o alarme
 * de relógio. A aplicação alarme.c deverá disparar um processo filho que,
 * logo após sua execução, dorme por 5 segundos antes de enviar um SIGALRM
 * ao processo pai. O processo pai, por sua vez, prepara-se para receber o sinal
 * do tipo SIGALRM, aguarda por esse sinal; quando o sinal é recebido, imprime
 * na tela a ocorrência do evento e, em seguida, se encerra. Faça o uso da
 * função pause(void) para aguardar pelo sinal enviado pelo processo filho.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void abort_program(void){
  int finish, read_success;

  read_success = scanf("%d\n", &finish);

  if(read_success && finish) {
    exit(0);
  }
}

int main(void) {
  pid_t pid;

  // Dispara o fork
  pid = fork();

  if(pid < 0) {
    printf("Algum erro aconteceu no fork\n");
    exit(0);
  }

  // Condicao executada dentro processo filho, se pid for outro numero maior
  // que 0 está sendo executado dentro do processo pai. Essa é a condição do else
  if(pid == 0 ) {
    printf("Processo filho vai dormir e lançar um sinal. pid = %d\n", getpid());

    // Dorme por cinco segundos
    sleep(5);

    // lanca um sinal que deveria ser capturado com pause
    alarm(10);
    printf("Sinal lançado!\n");
  } else {
    printf("Processo pai executando e esperando. pid = %d\n", getpid());
    // espera o SIGALRM
    pause();
    printf("Sinal capturado!!!\n");
    exit(0);
  }

  abort_program();

  return 0;
}
