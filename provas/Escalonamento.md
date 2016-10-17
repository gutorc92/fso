# Escalonamento

## Criterios de escalonamento

- Manter a CPU tanto quanto possivel ocupada, utilizando seus recursos da forma mais eficiente possivel.
- Taxa de processos completando suas execuções por unidade de tempo
- Quantidade de tempo para executar um processo especifico.
- Quantidade de tempo que um processo fica esperando na pilha
- Tempo de resposta entre uma requisição submetida até a primeira resposta ser produzida.

## Funcionamento
Ao escolher o processo, é necessário utilizar ele da forma mais eficiente possivel na CPU, pois a troca de processos é muito custosa. De inicio deve ocorrer o chaveamento do modo usuário para o modo root. Depois, o estado atual do processo deve ser salvo, armazenando-se inclusive seus registradores na tabela de processos, para que possam ser recarregados posteriormente. Em muitos sistemas o mapa de memória também deve ser salvo. Em seguida um novo processo precisa ser selecionado pela execução do algoritmo. Depois disso, a MMU tem de ser recarregada com o mapa de memória do novo processo. Por fim, o novo processo precisa ser iniciado. Além disso, a memória cache é recarregada da memória principal (Tanembaum, 2010, ADAPTADO).

Tanembaum divide os processos em orientados a E/S e orientados a CPU. Tal que os orientados a E/S realizam pouca computação, sendo caracterizados pelo tempo de demora das requisições de E/S. A partir disso ele preve que no futuro o escalonamento de processos orientados a E/S deverá ser importante no futuro, ao passo que o processamento da CPUs estão cada vez mais rápidas.

## Tipos de algoritmos de escalonamento

### Não Preemptivo
Basicamente esse escolhe um processo para executar de forma que não será suspenso até que seja liberado ou que a CPU seja bloqueada por uma espera de E/S ou de um outro processo(esperando resposta).

### Preemptivo
Já o preemptivo é um algoritmo que escolhe um processo para execução colocando um tempo fixado para suspende-lo(mesmo em execução). Então ele escolhe outro processo. Esse tipo de escalonamento precisa de uma interrupção de relógio para devolver o controle da CPU ao escalonador.

## Algoritmos de escalonamento

### First-come, First-Served
É o método mais elementar de escalonamento, basicamente consiste numa fila onde o último processo a chegar será o ultimo a ser executado. É um método não preemptivo e apesar de ser o mais fácil de ser implementado, conta com grande desvantagem de tempo, uma vez que processos com longos tempos de execução, como orientados a E/S por exemplo, consumirão muito tempo, enquanto processos mais pequenos vão continuar atrás.

### Shortest-Job-First
É uma forma que valoriza os processos menores em tempo de execução. Tal que se saiba previamente todos os tempos disponíveis. Esse é um método não-preemptivo e seu maior problema consiste no risco de processos longos nunca serem executados(Starvation). Uma possível solução para isso é colocar um número de prioridade associado a cada processo da fila . Existe ainda uma versão preemptiva desse método, que interrompe o processo corrente se um processo menor chegar na fila.

### Round robin
Cada processo obtêm uma pequena quantidade de tempo da CPU, chamado de quantum. Após certa unidade de quantum, se o processo ainda estiver em execução, ele é sofrerá preempção e será adicionado ao final da fila de espera.
