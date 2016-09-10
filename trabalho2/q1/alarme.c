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
 *
 * As observações desse programa em resposta ao enunciado estão no arquivo
 * README.md nessa mesma pasta.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void abort_program(void);
void handle_sigalrm(int signum);

int main(void) {
  pid_t pid;

  /**
   * Quando um sinal é lançado ele irá procurar um handler para executar antes
   * de retornar a execução normalmente. Se essa função:
   *
   * void handle_sigalrm(int signum)
   *
   * não for criada, ele não irá prosseguir a execução normal.
   */
  signal(SIGALRM, handle_sigalrm);

  // Dispara o fork
  pid = fork();

  if(pid < 0) {
    printf("Algum erro aconteceu no fork\n");
    exit(0);
  }

  /**
   * Condicao referente ao processo filho, se pid for um numero maior
   * que 0 está sendo executado dentro do processo pai.
   */
  if(pid == 0 ) {
    printf("Processo filho vai dormir e lançar um sinal. pid = %d\n", getpid());

    int pid_of_father = getpid()-1;

    // Dorme por cinco segundos
    sleep(5);

    // lanca um sinal que deveria ser capturado com pause
    kill(pid_of_father, SIGALRM);
  } else {
    printf("Processo pai executando e esperando. pid = %d\n", getpid());

    // espera o SIGALRM e imprime sua captura
    pause();

    printf("Sinal capturado\n");
  }

  abort_program();

  return 0;
}


void abort_program(void){
  int finish, read_success;

  read_success = scanf("%d\n", &finish);

  if(read_success && finish) {
    exit(0);
  }
}

/**
 * É necessário um handler para que o sinal seja lançado e o controle seja
 * retornado para o programa principal(nosso processo pai).
 */
void handle_sigalrm(int signum) {
  if(signum != SIGALRM) {
    printf("Wrong signal %d", signum);
  }

  printf("Lançou um SIGALRM\n");
}
