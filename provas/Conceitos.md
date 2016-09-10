# O que é um sistema operacional?

Segundo Silberschatz: É um programa que gerencia o hardware do computador. Ele também provê a base para programas de aplicação e actua como um intermediário entre o usuário de computador e o hardware do computador. Para o autor, bem como diversas literaturas, um sistema operacional tem objetivos bem definidos, na literatura citada é defendido que dentre suas regras estão:

- Executar programas de usuário e fazer da soluções dos problemas de usuário fáceis.
- Fazer o sistema do computador conveniente para uso.
- Usar o hardware do computador de maneira eficiente.

A história dos sistemas operacionais é conflituosa entre suas várias vertentes, pois diversos protagonistas definiram objetivos, filosofias e politicas diferentes para seus sistemas operacionais.

# Estrutura de um sistema de computador

Um computador pode ser divido em quatro categorias: Hardware, Sistema operacional, programas de aplicação e usuário(não apenas o humano, mas o proprio agente de interação com o sistema, podendo ser uma máquina ou outro computador).

# O que um sistema operacional faz?

Depende do ponto de vista, para um usuário comum, facilidade de uso e boa performance basta. Já para aplicações em dispositivos específicos e automóveis, usabilidade não é requisito tão necessário.

# Algumas definições de um sistema operacional

De maneira geral podemos definir o que um sistema operacional precisa essencialmente ter:

- Alocador de recursos
	- Gerência recursos, decidindo a requisições de forma eficiente e justa.
- Controlador de programa
	- Controla a execução de programas para previnir erros e o uso impróprio de um computador(hardware).

# Inicialização de computador

Bootstrap program é carregado junto ao ligamento ou reinicialização do computador. Tipicamente é armazenado em ROM ou EPROM, geralmente conhecido como firmware, ele inicializa todos os aspectos do sistema.

OBS: Esse é um dos motivos de ser tão crítico atualizar esse nível de software, pois está intimamente ligado ao hardware!

# Organização do computador

Uma ou mais CPU's, controladores de dispositivos estão conectados através de um barramento que fornece acesso a uma memória compartilhada. Execuções concorrentes de CPUs e dispositivos competem por ciclos de memória. Para operações de entrada e saida(I/O) cada dispositivo tem um buffer local, o qual a CPU envia ou recebe dados da memória principal. Assim que um controlador de dispositivo informa a CPU que sua operação está finalizada, ele lança uma interrupção.

# Lançamento de interrupção

A grosso modo, o sistema operacional preserva o estado da CPU salvando em registradores os contadores de programa, determina que tipo de interrupção deve ocorrer, então segmentos de código determinam que ação deve ser usada para cada tipo de interrupção. Logo uma interrupção é uma mudança na execução de contextos da CPU.

Existem interrupções de hardware e software. A primeira é gerada por um ou mais dispositivos que fazem uma requisição/envio de dados. A segunda, pode ser exceções ou traps, como software error, requisição de serviço de SO, etc.

# Process Management

Um processo é um programa em execução. É uma unidade de trabalho dentro do sistema. Um programa por si próprio não é um processo, um programa é uma entidade passiva, um processo é uma entidade ativa. 

Cada thread tem um program counter, especificando a localização da próxima instrução. Processos executam instruções sequenciais, uma por vez até que se completem.

# Serviços de sistema operacional

Sistemas operacionais fornecem um ambiente de execução de programas e serviços para outros programas e usuários. Existem uma série desses:

- User interface, Command-Line, Graphics User Interface
- Programas de execução, o sistema deve ser capaz de carregar um programa na memmória e executar o programa.
- Operações de I/O, um programa que dependa de uma entrada ou saída de dispositivo.
- Comunicação de processos, caso processos trabalhem com a mesma informação.

Logo temos uma camada entre sistema operacional e o usuário e outros programas que chamamos de programas de serviço ou simplesmente, serviços de sistema operacional.

# Chamadas de sistema

São típicas interfaces de programação para um serviço fornecido pelo sistema operacional. Tipicamente escrito em mais alto nível, comumente em linguagem C ou C++. Algumas dessas interfaces de programação(API) são POSIX(usadas pelo linux, unix, mac OS X), Win32(usadas pelo Windows).

# Tipos de chamadas de sistema

Existem diversos tipos: Controle de processo, Gerenciamento de Arquivos, Gerenciamento de dispositivos, manutenção de informação, comunicações e proteção. A maioria das operações computacionais ocorrem por meio de chamadas de sistemas.

# Programas de sistema

Programas de sistema fornecem um ambiente conveniente para desenvolvimento e execução de programas, algumas dessas interfaces são simples chamadas de sistema, outras são  mais complexas. Eles podem ser divididos em: Manipulação de arquivos, informação de estado, suporte a linguagem de programação, carregamento e execução de programa, comunicação, serviços de plano de fundo e programas de aplicações.
