# Memória

## Background

- Programas devem ser trazidos para memória e colocados dentro de um processo para rodar
- Memória principal e os registradores devem ser acessados diretament apenas pela CPU
- Registros são acessados a cada ciclo de clock
- A cache situa-se entre a memória principal e os registradores da CPU
- Proteção de memória via hardware para garantir operações corretas

## Registradores base e limit

Um par de registradores base e limit, podem ser usados para endereçar um um espaço lógico, onde base define a menor unidade de espaço físico de endereço memória  e o registrador limit define o tamanho do comprimento.   

Para proteção da memória, existe um hardware que compara cada endereço gerado no modo usuário com os registradores. Qualquer tentativa de um programa em execução do modo de usuário, de acessar a memória do sistema operacional, ou de outro usuário, resulta em um erro capturado pelo sistema operacional, que previne acesso afim de impedir que o codigo ou as estruturas de dados de outro usuário ou do sistema operacional sejam modificados.

Logo, para os registradores limit e base, apenas o sistema operacional pode carrega-los! Eles precisam de instruções privilegiadas, que são executadas em modo kernel.

## Endereço

Dependendo do gerenciamento de memória utilizado, o processo deve ser movido entre o disco e a memória durante sua execução. Os processos no disco que estão esperando, serão trazidos para a memória para execução formadas de fila de entrada. Assim, o procedimento comum é que seja selecionado um processo dentro dessa fila de entradas para ser carregado na memória, esperar esse processo executar acessando instruções e memória de dados, por fim terminando sua execução liberando espaço de memória e declarando esse espaço como disponível.

Como a memória é mapeada com inicio em 00000, é de se esperar que os processos de usuário utilizam a partir desse espaço fisico de memória. Mas não é assim que funciona. Essa abordagem afeta o endereço que os programas de usuário podem utilizar [1]. Dessa forma, os endereços de memória são utilizados de uma maneira simbolica, tal que um compilador realoca o endereço do código para um endereço real, algo como: 14 bytes a partir do inicio dessa parte de memória.

[1] OBS: Não é dito no Silberschatz o por que dessa explicação

De forma clássica, a ligação de instruções e uso de endereço de memória pode ser feito em alguns passos ao longo do caminho de um programa:

- Tempo de compilação
Se é conhecido em tempo de compilação onde o processo irá se ocupar em memória, então o código absoluto será gerado. Logo, se  um processo sabe que sua localização inicia em R, então o compilador irá gerar um código que irá iniciar  em uma área extendida a partir dali.
- Tempo de carregamento
Se não é conhecido o tempo de compilação de onde o processo ocupa em memória, então o compilador deve gerar uma realocação de código.
- Tempo de execução
Se o processo pode ser movido em memória durante a sua execução então ele deve ser atrasado para o tempo de execução. Isso exige suporte de hardware.

## Endereço lógico vs Endereço Físico

Um endereço gerado por uma CPU é comumente referenciado como um endereço lógico, que é uma unidade de mensuramento de memória, ou seja registro de endereçamento de memória, é comumente associado a um endereço físico.

Em tempo de execução, o mapeamento do endereço virtual(endereço lógico) para o físico é feito por um hardware chamado memory-management unit(MMU). O que conhecemos como registrador base é para o MMU o registrador de realocação. O valor de realocação de registro é adicionado a cada endereço gerado pelo processo de usuário. Então se o base é 14000, então uma tentativa do usuário de acessar o endereço 0 é realocada dinamicamente para a localização 14000.

O programa de usuário nunca ve o real endereço físico. Um programa pode criar um ponteiro de localização qualquer, manipular isso, comparar com outro endereço, e no final ele estará usando um endereço real com base no realocador relativo  do registrador base.

## Carregamento dinâmico

Para execução de um programa, deve-se carregar todos os dados no processo executado. O tamanho do processo é limitado ao tamanho da memória física. Logo para obter uma melhor utilização de espaço de memória, nós usamos o carregamento dinâmico. Com isso uma rotina só é carregada quando é chamada. Todas elas ficam no disco esperando em um formato realocável.

Quando uma rotina é chamada é verificado se outra rotina foi carregada, se não, é chamada para carregar a rotina desejada na memoria, fazendo atualizações na tabela de endereços do programa principal. Então o controle é passado para essa nova rotina. A vantagem desse tipo de carregamento é que rotinas inutilizadas jamais estão carregadas na memória. Nesse caso, o programa total pode ser grande, mas a porção usada deve ser muito pequena.

Carregamento dinamico não requer nenhum suporte especial do sistema operacional. Isso é responsabilidade dos usuários do SO, projetarem um programa para lidar com essa vantagem. Sistemas operacionais devem ajudar o programador, entretando, apenas provendo bibliotecas de rotinas para impelementarem carregamento dinamico.

## Swapping

Um processo precisa estar na memória para ser executado. Entretanto, um processo pode ir temporarimente para a fora da memória para armazenamento em disco, sendo trazido mais tarde para continuar sua execução. Esse recurso otimiza a ocupação de espaço. Imagine vários programas ocupando toda memória, se um de seus processos ficar inativado por muito tempo, não faz sentido ficar ocupando memória, melhor seria joga-lo para a memória swap e resgata-lo quando necessário. Para swap existem algumas condições comuns:

- Swap normalmente é desativado, inicia se um limite de memória for alocado
- Desativada quando a memória limite estiver em disponibilidade

## Alocação continuada de memória

A memória principal deve suportar manter ambas processos: usuário e do sistema operacional. Existem entretanto várias formas de se fazer isso.

Um dos métodos mais comuns de se fazer alocação de memória é dividir a memória em alguns tamanhos-fixos de partição. Cada partição contendo exatamente um processo, tal que quando uma partição está livre, um processo é selecionado na fila de entradas e carregado nessa partição. Quando o processo termina, a partição volta disponível para outro processo.

Em um modelo de partição variável, toda a memória está livre e é considerada como uma hole(ideia de buraco, espaço), a memória contém uma coleção de holes de vários tamanhos.

Quando um processo entra no sistema ele é colocado na fila de entradas. Então o sistema operacional visualiza quanto existe de memória disponível e quanto é requisitado para um processo ser executado. Facilmente, o sistema coloca cada processo em um hole, até que um processo requisitado não tenha um bloco de memória(hole) grande o suficiente. Então o sistema operacional espera por um hole, ou procura um próximo processo que pode ocupar os espaços disponível.

De modo geral, uma memória é uma coleção de holes de diversos tamanhos. Quando um processo tem sua vez e precisa de memória, o sistema procura por uma hole de tamanho equivalente ao requisitado. Se o hole é muito grande, ele é dividido em duas partes, uma é alocada para o processo a outra volta para o conjunto de holes. Esse procedimento é uma instance particular de se resolver problemas de alocação dinâmica de memória. Existem muitas soluções, algumas estratégias são: First fit, Best fit and Worst fit.  

- First fit
Procura por um hole grande o suficiente a partir do inicio dos blocos, assim que encontra um hole suficientemente grande, para a procura.

- Best fit
Aloca o menor hole suficientemente grande para o processo.

- Worst fit
Aloca o mais largo hole, está estratégia deixa a maior quantidade de sobra. De novo, deve-se procurar em toda lista a menos que ela seja ordenada.

## Fragmentação

Ambas, first-fit e best-fit sofrem de fragmentação externa. Nessas estratégias, quando um hole é liberado o espaço de memória é quebrado em várias partes, em algum tempo haverá memória continuada disponível, mas ela estará fragmentada e não poderá ser usada. Isso é um problema grave, chamado de fragmentação externa. Uma solução para isso é permitir que o espaço de endereço lógico não seja contiguo, alocando memória de acordo com o que estiver disponível. Duas técnicas complementares é a paginação e segmentação.

## Compactação

Uma das soluções para framentação é a compactação, ela embaralha todo o conteudo da memória para um único e grande bloco, porém ela não pode ser executada sempre, existe a restrição de ser possivel usa-la em realocação dinâmica e em execução.

## Paginação

É um tipo de gerenciamento de memória que permite o endereçamento fisico de memória de um processo de forma não contigua. Paginação evita a fragmentação e a necessidade de compactação. Essa técnica resolve o problema de achar um espaço de tamanho váriavel, relativo a memória no armazenamento backup, através de swap. Esse problema surge pelo fato de que no armazenamento de persistencia sofre dos mesmos problemas de fragmentação da memória principal, e como o acesso a essa memória é muito lento, compatação não é uma técnica viável. Por causa das várias vantagens desse método, paginação é utilizada em vários sistemas operacionais.

Tradicionamente paginação é utilizada por hardware, mas recentemente tem sido implementado paginação integrando hardware e sistema operacional.

## Método básico

O metodo básico de paginação consiste em dividir a memória física em blocos chamados de quadros, e em equivalentes tamnhos de memória lógica chamados de paginas. Então quando um processo está para ser executado, paginas de memória disponíveis são carregadas, tanto páginas da memória principal, quanto do backing store, que também é dividido em blocos de mesmo tamanho dos quadros da memória principal.

Cada endereço gerado pela CPU é dividido em numero de página e deslocamento de página. O número da página é usado na tabela de páginas como um indice. A tabela de páginas contem o endereco de cada página na memória física. Logo, o numero da página combinado com o deslocamento da pagina define o endereço que é enviado para a unidade de memória.

Tanto o tamanho da página quanto o tamanho do quadro é definido pelo hardware. O tamanho da página é tipicamente uma potência de 2, variando dentre 512bytes e 16 megas por página a depender da arquitetura do computador. Isso facilita a tradução do endereçamento logico. Se o tamanho do endereço lógico é 2^m e o tamanho da página é 2^n unidades de endereçamento, então o número da página está na ordem da diferença de m-n, enquanto n é o deslocamento da página. Exemplo:

Para um endereço lógico com n=2 e m=4, usando um tamanho de página de 4 bytes e uma memória física de 32bytes(8 paginas, 32/4). Endereço lógico 0 é dá página 0, deslocamento 0. Arquivado na página da tabela, encontramos que a página 0 está no quadro 5. Logo, endereço lógico 0 é mapeado para o endereço físico 20(5x4+0). Portanto o endereço lógico 3(pagina 0, deslocamento 3) será mapeado para o endereço físico 23((5x4)+3). Agora para um Endereço lógico 4 que está na pagina 1 com deslocamento 0. Para a tabela de pagina, pagina 1 está mapeada para o frame 6. Assim, o endereço lógico 4 mapeado para o endereço físico 24(6x4 + 0). (Ver figura 7.9, pagina 293)

Quando  usamos o esquema de paginação, não temos o problema de fragmentação externa pois qualquer quadro de memória pode ser alocado para o processo que precisar dele. Entretanto existe um pouco de fragmentação interna, pois se um programa aloca uma quantidade de paginas, o ultimo frame alocado pode não estar completado. No pior caso, imagine que um programa precise de n páginas mais um byte, ele deverá alocar n + 1 frames, resultando numa fragmentação de quase todo frame.

Se o tamanho de um processo é indepenpendente do tamanho da pagina, é esperado que a fragmentação interna seja pelo menos metade de uma página por processo. Isso sugere que paginas pequenas são preteriveis. Entretanto, aqui temos um overhead, pois se tivermos muitas páginas pequenas, nossa tabela de paginas fica cada vez maior. Também deve ser considerado que as operações I/O são mais eficientes quando a quantidade de dados a ser transferidas são maiores.

Quando um processo surge para ser executado, seu tamanho expresso em paginas é examinado, cada página de um processo precisa de um frame. Se ele precisar de n paginas, n frames devem estar disponiveis. Caso estejam isso é alocado para o processo. A primeira página de um processo é carregada em um dos frames alocados e o número de frames é colocado na tabela de páginas de um processo. Um importante aspecto disso, é que para a visão do usuário temos um único espaço de memória que contém o programa, enquanto de fato o programa está espalhado por toda memória física. Essa diferença é relacionada através de um hardware que faz tradução de endereçamento. O endereço lógico é traduzido para endereço físico. Esse mapeamento é escondido do usuário sendo ele controlado pelo sistema operacional.

O sistema operacional quando gerenciador da memória deve infomara alguns detalhes da memória física: quais frames são alocados, quais estão dispníveis, etc.  Essas informações costumam estar em uma estrutura de dados chamada de tabela de frames.

Além do mais, o sistema operacional deve ser informado sobre o espaço de usuário usado em um processo, para que toda memória lógica possa ser mapeada para produzir memória física. Se um usuário faz uma chamada de sistema(I/O por exemplo) e prove um parametro como um buffer ou instancia, o endereço deve ser mapeado para produzir um endereço físico correto.

## Suporte de hardware

O hardware da tabela de pagina pode ser feito de diversas maneiras. Em um caso simples, a tabela de página é implementada como uma coleção de registradores dedicados. O motivo para isso ser feito usando registradores é para que a tradução de endereçamento de paginas seja eficiente.

Para arquiteturas cujo a tabela de páginas é razoavelmente pequena(256 entries), o uso de registradores é sucificiente. Mas a maioria dos  computadores modernos usam muito além disso(1 milhão). Para essas máquinas o uso de registradores base de tabela de páginação(PTBR) de pontos de tabela de paginação. Mudando a tabela de paginas requer a mudança apenas desse único registrador, aumentando substancialmente o tempo de troca de contexto.

O problema com essa abordagem é o tempo requisitado para acessar a localização da memória, que pode ser medido por um fator de 2. Esse atraso pode ser intolerável em muitas circunstâncias. A solução para esse problema é sar o cache especial chamado de TLB, buffer de tradução olhe para o lado. O TLB é associativo, de rápida memória. Cada entrada do TLB consiste em duas partes. Uma chave e um valor. Quando a memória apresentada com o item é comparada com todas as chaves simultaneamente. Se nenhum item é localizado, o correspondente campo é retornado.

A porcentagem de número de páginas  que são encontradas no TLB é chamada de hit ratio. Existe uma probabilidade de 80 por cento de encontrar uma página no TLB, 20 por cento de ser necessário pega-la na memória. Para o acesso no TLB é gasto em torno de 120 nanosec e 220 nanosec para pega-la na memória. Para achar o tempo efetivo de acesso a memória podemos fazer:

effective access time = 0.80 x 120 + 0.20 x 220

## Protection

Proteção de memória num ambiente paginado é acompanhado pela proteção de bits associada a cada frame. Nós podemos criar hardware para prover proteção de apenas leitura, apenas escrita ou apenas execução. Tentativas ilegais vão ser capturadas pelo sistema operacional. Um bit adicional é geralmente usado como entrada na tabela de paginas como um valido-invalido bit. O sistema operacional configura esse bit para cada processo seguir ou não seguir o acesso a uma página.

## Shared Pages
Uma vantagem da paginação é a possibilidade de compartilhar código. Vários processsos podem executar o mesmo código ao mesmo tempo, uma vez que o código para um processo não muda em tempo de execução. Cada processo mantém uma cópia de registradores e dados de armazenamento para guardar os dados de execução do processo.

Para um programa em execução sendo executado por diversos processos de usuário, apenas uma copia é mantida em memória física, enquanto cada pagin de dado, referente aos processos, são mantidos em quadros de memória diferentes. A natureza de apenas-leitura deve ser mantida para que o codigo permaneça correto. O sistema operacional pode apoiar essa propriedade.

## Estrutura da tabela de paginas
O tamanho típico de uma página é de 4 KiB. Assim, para um espaço de endereçamento de 32 bits, cada processo tem acesso a 4 GiB de memória virtual, o que corresponde a 1 MB de páginas de memória. Como normalmente cada entrada tem 4B de tamanho (32 bits), cada processo teria uma tabela de 4MiB de tamanho. Dado o elevado número de processos que correm simultaneamente num sistema, rapidamente uma significativa parte da memória serviria apenas para tabelas de páginas, ao invés da informação propriamente dita(WIKIPEDIA^).

Para resolver este problema recorre-se a algumas estratégias que tentam minimizar a memória utilizada para a indexação de endereços bem sem prejudicar o desempenho. (WIKIPEDIA^)

## Hashed page table

## Inverted Page table

## Segmentação
É o esquema gerenciador de memória que permite a visão de memória do usuário. Um espaço de endereço lógico é um conjunto de segmentos. Cada segmento tem nome e tamanho.  Por simplicidade de implementação, segmentos são numerados e são referidos por um número de segmento em vez de nome. Logo um endereço lógico é composto de numero de segmento e offset.

### Hardware
