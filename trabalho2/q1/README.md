## Observa��es
Para lan�ar o SIGALRM foi utilizado a fun��o kill(2), respons�vel por mandar
um sinal para outro processo. Outras fun��es como alarm(void) lan�am um SIGALRM,
por�m apenas para o processo corrente, al�m do que, na documenta��o h� recomenda��o
para n�o se utilizar ele com sleep(int sec), outra fun��o utilizada na quest�o.

-Para explica��o do c�digo, visualizar a documentation.html na pasta anterior
-Ver tamb�m o t�pico de sinais do Advanced Linux Programming
