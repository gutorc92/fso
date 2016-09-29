# Shared Library

Para compilar uma biblioteca dinâmica(ou compartilhada), é necessário seguir alguns passos que estão detalhadamente descritos no livro Advanced Linux Programming. Tutorial de compilação dos arquivos dessa pasta está no arquivo documentation.html.

# Questões

* Em relação ao programa que contempla os itens a) e b), quais foram as alterações de códigos-fonte necessárias para a solução (se houverem)?

Nenhuma alteração de código fonte, toda diferença entre ambos se resume na forma de compilação, na biblioteca dinâmica o executável final não possui o código da biblioteca compartilhada, invés disso ela é simplesmente referenciada.

* Dados os conhecimentos adquiridos em função desse trabalho, indique vantagens e problemas decorrentes da utilização de bibliotecas dinâmicas?


## Gerando parte do objeto compartilhado

A diretiva -fPIC do gcc é responsável por tornar os códigos da biblioteca dinâmica para diferentes endereços em diferentes programas.

$ gcc -c -fPIC libprimo.c

Agora que temos nosso código como necessário para criação de biblioteca dinâmica, usaremos:

$ gcc -shared -fPIC -o libprimo.so libprimo.o

Serão combinados os arquivo '.o' que irão gerar libprimo.so

Se esse arquivo de extensão .so for colocado em /usr/lib no Linux, então bastaria rodar:

$ gcc -o main main.c libprimo.o -lm -std=c99 -L. -lprimo

Porém para rodar na pasta local, deve-se usar a diretiva -Wl,-rpath, (directory), como:

$ gcc -o main main.c libprimo.o -lm -std=c99 -L. -lprimo -Wl,-rpath,/home/kuwener/workspaces/C/fso/trabalho3

Para rodar os procedimentos acima, basta usar:

$ make

Dois programas serão gerados prog e prog2, o primeiro não utiliza bibliotecas
dinâmicas e o segundo que as utiliza.

Para verificar se o arquivo prog2 realmente foi copilado com a biblioteca de
forma dinâmica basta usar o comando:

$ ldd prog2

O comando ldd irá mostrar todas as bibliotecas atreladas ao arquivo, exibindo
assim a biblioteca libprimo.so.
