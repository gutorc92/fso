#Entrada e saída

O gerenciador de entrada e saída é uma grande composição de componentes do desenho de um sistema operacional. Alguns aspectos a serem considerados são:

* Dispositivos de Entrada e saída variam amplamente Existem vários metodos para
* controle Novos dispositivos são frequentes Portas e barramentos são conectados
* a  controladores de dispositivos.
* Drivers encapsulam detalhes de dispositivos
* Existem muitas variedades de dispositivos de E/S

##Hardware de Entrada e saida

Dispositivos comumente tem registradores o qual os drivers de dispositivos usam para comandos, endereços e escrever e ler dados. Dispositivos tem endereços usados pelas instruções de Entrada e saída. Endereços são mapeados para espaço de endereço do processador(Acho que utilizados por ele).

##Polling or Espera ativa

Para cada byte de entrada e saída, temos que:

* É lido como ocupado cada bit do registrador de status, até ocupado ser 0
* Host configura para ler ou escrever o bit e se escreve, copia dados para registrador de saída.
* Host configura o bit de comando pronto
* Controlador configura bit de ocupado, executa a transferênca
* Controlador limpa bit de ocupado, de erro, de comando pronto quando a transferência está pronta.

Passo 1 é chamado espera ativa:
* Razoável se o dispositivo é rápido
* Ineficiente se o dispoitivo é lento, informação pode ser inclusive perdida, se a CPU mudar para outro processo.
* O dispositivo de hardware que notifica a CPU sobre a ativação de dispositivo é chamada interrupção.
* Existe um manipulador de interrupção que recebe interrupções mascaráveis.
OBS: Interrupções mascaráveis são aquelas que podem ser ignoradas, pois não são tão urgentes, enquanto não mascaráveis tem alta prioridade e são executadas no momento em que são lançadas.
* Vetor de interrupção para envio de interrupção para o manipulador certo(têm vários)

## Interrupções
O mecanismo de interrupção é usado também por exceções, crashs de sistema, erro de hardware, falha de páginação quando a memória executa um erro. O sistema operacional pode lançar uma trap(exceção para alguma condição inválida).

## Direct Memory Access
* Usado para evitar programação de entrada e saída de um bit por vez.
* Requer um controlador DMA.
* Evita a CPU tranferir dado diretamente entre entrada e saída e memória
* OS escreve bloco de DMA dentro da memória.

## Interface de aplicação de Entrada e saída

* O sistema de entrada e saída encapsula dispositivos em classes genéricas.
* A camada de drivers de aplicação esconde as diferenças entre os diferentes controladores de E/S do kernel

## Caracteristicas de dispositivos de E/S

Comumente os dispositivos são classificados pelo SO em:

* Bloco de E/S
* Caractere de E/S
* Memória mapeada de acesso de arquivo
* Socket de network

## Asincrono I/O e não blocante

## Blocante
Processo que suspende até I/O estar completado.
* Fácil de usar e entender
* Insuficiente para algumas necessidades

## Não Blocante
Chamada de E/S retorna tanto quanto disponível. Processo roda enquanto E/S executam
* Implementada via multi-threading
* Retorna rapidamente com contade de bytes lidos ou escritos
* Dificil para usar
* Subsistema de sinais de E/S processão quando E/S está completo

## Subsitema de E/S do Kernel
#### Escalonamento
O sistema operacional é encarregado da implementação de escalonamento da fila de requisições por um dispositivo. O escalonador de E/S rearranja a ordem da fila para manter a eficiencia de um sistema no geral e a média de resposta de tempo das aplicações. Quando o kernel suporta E/S assincrona dev ser capaz de manter mapeado varias requisições no mesmo tempo, para isso o sistema operacional mantem uma fila numa tabela de status de dispositivos. O Kernel gerencia essa fila. Essa é uma das formas de prover eficiência em processos de E/S.

Tópicos abaixo são baseados:
https://techbask.wordpress.com/2012/03/05/spooling-buffering-caching-whats-the-difference/
#### Buffering.
Guarda dados na memória enquanto transfere entre dispositivos.(Tem mais)
* Dados pré-carregados em uma área reservada de memória(buffer)
* Guarda temporariamente os dados de entrada e saída para melhorar a velocidade entre dois dispositivos, CPU e disco.

#### Spooling

* Acrônimo para “Simultaneous Peripheral Operation On-Line”
* É o processo de colocar um dato temporariamente numa área de traballho para um process processar.
* É util se um dispositivo serve apenas uma requisição por vez, é necessário deixar o dado para quando estiver disponivel, ser utilizado


## E/S protection
Processos de usuário podem ser acidentalmente ou propositalmente efetuar operacões ilegais via E/S. Para que isso não ocorra é necessário que toda instrução de E/S seja definida para ser privilegiada. Operações de E/S são efetuadas através de chamadas de sistema.
