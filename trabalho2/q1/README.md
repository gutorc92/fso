## Observações
O sinal não foi capturado na execução. Pesquisando a documentação das funções sleep e alarm no sistema operacional linux utilizado (Debian), encontramos na seção de observações a seguinte mensagem:

*sleep(3) may be implemented using SIGALRM; mixing calls to alarm() and sleep(3) is a bad idea.*

Porém os detalhes dessa limitação não foram expressos, ao pesquisar mais, encontramos em um [tópico](http://stackoverflow.com/questions/19972318/when-a-process-call-the-sleep-function-does-it-emit-a-signal) a seguinte explicação:

*"[...] In other words, signal is sent after sleep is finished sleeping, just not to the parent process - but to process which called sleep. And parent process cannot intercept signals delivered to its child."*

Logo, o processo pai não consegue capturar o sinal do alarm, pois assim como o sleep é tangivel apenas ao seu processo, o alarm também é (afinal os dois usam SIGALRM). Logo o pause do processo pai vai ficar esperando um sinal que não foi lançado para ele.
