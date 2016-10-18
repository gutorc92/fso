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

### Priority
A ideia básica é que cada processo seja atribuida uma prioridade, tal que o de maior prioridade irá executar, mesmo que em execução, algum processo obtenha maior prioridade, pois para evitar que os processos de alta prioridade executem indefinidamente pode-se utilizar da estratégia de reduzir o tempo de execução dos processo atual a cada ciclo de relógio.

### Round robin
Cada processo obtêm uma pequena quantidade de tempo da CPU, chamado de quantum. Após certa unidade de quantum, se o processo ainda estiver em execução, ele é sofrerá preempção e será adicionado a fila de espera e o processo será chaveado. Se for bloqueado ou tiver terminado antes do quantum ter decorrido, será chaveado também. A preempção é útil aqui apenas quando o processo é bloqueado, pois processos pequenos podem ser prejudicados ficando em espera. Já muita preempção é prejudicial, tal que é reduzido a eficiência uma vez que chaveamentos são muito custosos. É preciso saber um quantum equilibrado.

## Escalonamento de thread
O sistema operacional também faz gerenciamento de threads em nível de kernel e usuário. O nível de usuário é gerênciado por uma biblioteca de threads. Para rodar threads de nível de usuário, deve ser mapeado em ultima analise para uma thread de kernel. Esse mapeamento pode ser indireto e pode usar de um processo leve (LWP).

## Problemas clássicos de IPC
Vários problemas interessantes(engraçados também) foram criados para resolver questões de ampla discurssão sobre os métodos de gerênciamento.

### Problema do jantar dos filósofos
Imagine a situação: Cinco filósofos estão jantando em uma mesa circular. Cada filosofo tem um prato de espaguete. O espaguete precisa ser comido com dois garfos, mas entre cada par de pratos está um único garfo. Sendo que, a situação dos filosofos pode se resumir a comer e pensar. Quando um filosofo fica com fome ele tenta pegar os garfos á sua direita e a sua esquerda. Um de cada vez, em qualquer ordem. Se conseguir pegar os dois garfos ele comerá durante um tempo, então voltará a pensar, colocando os garfos na mesa. A questão central é: Como fazer uma rotina para cada filósofo de modo que nenhum deles trave?

### O problema dos leitores escritores
Imagine, por exemplo, um sistema de reserva de linhas aéreas, com muitos processos em competição, querendo ler e escrever. É aceitável que múltiplos processos leiam a base de dados ao mesmo tempo, mas, se um processo estiver atualizando(escrevendo na base de dados), nenhum outro processo pode ter acesso ao banco de dados, nem mesmo os leitores. Como programar os leitores e os escritores?

### O problema do produtor-consumidor
Esse problema consiste em dois processos, um que produz e outro que consome dados em comum. Um buffer fixo é usado como uma pilha de tamanho fixo, o qual o produtor preenche ela enquanto o consumidor acessa ela continuamente. O problema está em garantir que o produtor não irá adicionar dado quando esse buffer estiver cheio e o consumidor não irá consumi-lo quando estiver vazio.
