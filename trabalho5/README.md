## Semáforo e usleep
No enunciado do problema é possivel encontrar duas observações:
* Uma thread jamais interromperá a outra thread no momento da impressão em
tela
* E cada thread deverá aguardar, no mínimo, 500 ms entre a impressões em tela

Logo foram utilizadas duas bibliotecas: unistd.h e semaphore.h. A primeira prove a função usleep que para a execução da thread e a segunda pthread_mutex_lock e pthread_mutex_unlock, são implementações de semáforo.

## Resolução

Para resolução desses problemas, foi utilizado o seguinte código:
```c
// waiting Ctrl + C
while(keep_looping) {
  pthread_mutex_lock(&print_mutex);
  printf("%s\n", text);
  pthread_mutex_unlock(&print_mutex);
  count_lines_thread[p->nr_outputs-1]++;
  usleep(500000);
}
```

Uma execução gerou os seguintes resultados:
`
$ ./prog 3
bb
ccc
a
ccc
a
bb
ccc
a
bb
ccc
a
bb
ccc
bb
a
ccc
bb
a
ccc
bb
a
ccc
a
bb
ccc
bb
a
ccc
a
bb
ccc
bb
a
ccc
a
bb
^CEncerrando aplicação.Aguardando finalização de threads
Aplicação encerrada com sucesso!
Estatísticas:
thread 1: 12
thread 2: 12
thread 3: 12
`

Percebe-se que as threads executaram a mesma quantidade de vezes. O que acontece é que o tempo de 500ms é muito pequeno para que aconteça diferença, uma vez que a maior parte do tempo a thread passa dormindo, isso permite que todas as threads executem quase que ao mesmo tempo. Se reduzirmos esse tempo para por exemplo 50 microsegundos, temos a seguinte estatística:

`
Estatísticas:
thread 1: 8669
thread 2: 8682
thread 3: 8638
`
