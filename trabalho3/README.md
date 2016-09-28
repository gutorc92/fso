# Shared Library

Para compilar uma biblioteca dinâmica(ou compartilhada), é necessário seguir alguns passos que estão detalhadamente descritos no livro Advanced Linux Programming. A seguir um breve resumo:

## Gerando parte do objeto compartilhado

A diretiva -fPIC do gcc é responsável por tornar os codigos da biblioteca dinâmica com diferentes endereços em diferentes programas. Para usa-la basta:

$ gcc -c -fPIC libprimo.c

Agora que temos nosso código como necessário para criação de biblioteca dinâmica, usaremos:

$ gcc -shared -fPIC -o libprimo.so libprimo.o

Serão combinados os arquivo '.o' que irão gerar libprimo.so

Se esse arquivo de extensão .so for colocado em /usr/lib no Linux, então bastaria rodar:

$ gcc -o main main.c libprimo.o -lm -std=c99 -L. -lprimo

Porém para rodar na pasta local, deve-se usar a diretiva -Wl,-rpath, (directory), como:

$ gcc -o main main.c libprimo.o -lm -std=c99 -L. -lprimo -Wl,-rpath,/home/kuwener/workspaces/C/fso/trabalho3


Para rodar os procedimentos acima, basta usar:

$ Make -f MakefileShared
