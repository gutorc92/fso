## Observa��es
O sinal n�o foi capturado na execu��o. Pesquisando a documenta��o das fun��es
sleep e alarm no sistema operacional linux utilizado (Debian), encontramos na
se��o de observa��es a seguinte mensagem:

*sleep(3) may be implemented using SIGALRM; mixing calls to alarm() and sleep(3) is a bad idea.*

Por�m os detalhes dessa limita��o n�o foram expressos, ao pesquisar mais, encontramos em um t�pico(http://stackoverflow.com/questions/19972318/when-a-process-call-the-sleep-function-does-it-emit-a-signal) a seguinte explica��o:

*[...] In other words, signal is sent after sleep is finished sleeping,
just not to the parent process - but to process which called sleep.
And parent process cannot intercept signals delivered to its child.*

Logo, o processo pai n�o consegue capturar o sinal do alarm, pois assim como o
sleep � tangivel apenas ao seu processo, o alarm tamb�m � (afinal os dois usam SIGALRM).
Logo o pause do processo pai vai ficar esperando um sinal que n�o foi lan�ado para ele.
