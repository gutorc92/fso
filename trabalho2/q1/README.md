## Observações
Para lançar o SIGALRM foi utilizado a função kill(2), responsável por mandar um sinal para outro processo. Outras funções como alarm(void) lançam um SIGALRM, porém apenas para o processo corrente, além do que, na documentação há recomendação para não se utilizar ele com sleep(int sec), outra função utilizada na questão.

-Para explicação dos procedimentos para execução, visualizar a documentation.html na pasta anterior

-Ver também o tópico de sinais do Advanced Linux Programming
