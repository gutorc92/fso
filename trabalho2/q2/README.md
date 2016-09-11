# N�mero de threads
No enunciado completo era questionado o n�mero de threads, por que n(n-1)/2 em vez de (n^2). Isso se d� pelo fato de que n^2 iria repetir as compara��es, enquanto a primeira formula prev� a compara��o entre dois numeros apenas 1 vez.

# Quest�es de �nalise
Executando o programa q2, que usa threads temos a seguinte sequ�ncia (gerada usando $seq 50, modificando o numero 25 para 100) no console:

$ time ./q2 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 100 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
Number of input values = 50
Input values X = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 100 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
After initialization W = 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Thread T(24, 25) compares x[24] and x[25], and writes 0 into w[25]
Thread T(24, 26) compares x[24] and x[26], and writes 0 into w[26]
Thread T(24, 27) compares x[24] and x[27], and writes 0 into w[27]
Thread T(24, 28) compares x[24] and x[28], and writes 0 into w[28]
Thread T(24, 29) compares x[24] and x[29], and writes 0 into w[29]
Thread T(24, 30) compares x[24] and x[30], and writes 0 into w[30]
Thread T(24, 31) compares x[24] and x[31], and writes 0 into w[31]
Thread T(24, 32) compares x[24] and x[32], and writes 0 into w[32]
Thread T(24, 33) compares x[24] and x[33], and writes 0 into w[33]
Thread T(24, 34) compares x[24] and x[34], and writes 0 into w[34]
Thread T(24, 35) compares x[24] and x[35], and writes 0 into w[35]
Thread T(24, 36) compares x[24] and x[36], and writes 0 into w[36]
Thread T(24, 37) compares x[24] and x[37], and writes 0 into w[37]
Thread T(24, 38) compares x[24] and x[38], and writes 0 into w[38]
Thread T(24, 39) compares x[24] and x[39], and writes 0 into w[39]
Thread T(24, 40) compares x[24] and x[40], and writes 0 into w[40]
Thread T(24, 41) compares x[24] and x[41], and writes 0 into w[41]
Thread T(24, 42) compares x[24] and x[42], and writes 0 into w[42]
Thread T(24, 43) compares x[24] and x[43], and writes 0 into w[43]
Thread T(24, 44) compares x[24] and x[44], and writes 0 into w[44]
Thread T(24, 45) compares x[24] and x[45], and writes 0 into w[45]
Thread T(24, 46) compares x[24] and x[46], and writes 0 into w[46]
Thread T(24, 47) compares x[24] and x[47], and writes 0 into w[47]
Thread T(24, 48) compares x[24] and x[48], and writes 0 into w[48]
Thread T(24, 49) compares x[24] and x[49], and writes 0 into w[49]
After step 2
W = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Maximum = 100
Location = 24


real	0m0.024s
user	0m0.004s
sys	0m0.024s

J� para o programa sem threads, q2wt(question 2 without thread), temos:

$ time ./q2wt 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 100 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
Number of input values = 50
Input values X = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 100 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
After initialization W = 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Thread T(24, 25) compares x[24] and x[25], and writes 0 into w[25]
Thread T(24, 26) compares x[24] and x[26], and writes 0 into w[26]
Thread T(24, 27) compares x[24] and x[27], and writes 0 into w[27]
Thread T(24, 28) compares x[24] and x[28], and writes 0 into w[28]
Thread T(24, 29) compares x[24] and x[29], and writes 0 into w[29]
Thread T(24, 30) compares x[24] and x[30], and writes 0 into w[30]
Thread T(24, 31) compares x[24] and x[31], and writes 0 into w[31]
Thread T(24, 32) compares x[24] and x[32], and writes 0 into w[32]
Thread T(24, 33) compares x[24] and x[33], and writes 0 into w[33]
Thread T(24, 34) compares x[24] and x[34], and writes 0 into w[34]
Thread T(24, 35) compares x[24] and x[35], and writes 0 into w[35]
Thread T(24, 36) compares x[24] and x[36], and writes 0 into w[36]
Thread T(24, 37) compares x[24] and x[37], and writes 0 into w[37]
Thread T(24, 38) compares x[24] and x[38], and writes 0 into w[38]
Thread T(24, 39) compares x[24] and x[39], and writes 0 into w[39]
Thread T(24, 40) compares x[24] and x[40], and writes 0 into w[40]
Thread T(24, 41) compares x[24] and x[41], and writes 0 into w[41]
Thread T(24, 42) compares x[24] and x[42], and writes 0 into w[42]
Thread T(24, 43) compares x[24] and x[43], and writes 0 into w[43]
Thread T(24, 44) compares x[24] and x[44], and writes 0 into w[44]
Thread T(24, 45) compares x[24] and x[45], and writes 0 into w[45]
Thread T(24, 46) compares x[24] and x[46], and writes 0 into w[46]
Thread T(24, 47) compares x[24] and x[47], and writes 0 into w[47]
Thread T(24, 48) compares x[24] and x[48], and writes 0 into w[48]
Thread T(24, 49) compares x[24] and x[49], and writes 0 into w[49]
After step 2
W = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Maximum = 100
Location = 24


real	0m0.002s
user	0m0.000s
sys	0m0.000s

A principio pensamos que por usar de threads o programa naturalmente ir� executar mais r�pido, por�m se pensarmos na quantidade de threads que foram criadas e que isso tamb�m � custoso para o sistema, nasce a hip�tese que a diferen�a de discrepante de 10x no programa que usa thread se d� por isso. Para provarmos essa hipotese foi criado um novo programa que aloca menos threads, diferente do primeiro, esse ir� alocar uma quantidade de (n-1) threads, tal que cada thread compare um n�mero da sequ�ncia com todos os outros. Esse execut�vel se chama q2op(question 2 optimized) e sua execu��o gerou:

$ time ./q2op 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 100 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
Number of input values = 50
Input values X = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 100 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
After initialization W = 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Thread T(24, 25) compares x[24] and x[25], and writes 0 into w[25]
Thread T(24, 26) compares x[24] and x[26], and writes 0 into w[26]
Thread T(24, 27) compares x[24] and x[27], and writes 0 into w[27]
Thread T(24, 28) compares x[24] and x[28], and writes 0 into w[28]
Thread T(24, 29) compares x[24] and x[29], and writes 0 into w[29]
Thread T(24, 30) compares x[24] and x[30], and writes 0 into w[30]
Thread T(24, 31) compares x[24] and x[31], and writes 0 into w[31]
Thread T(24, 32) compares x[24] and x[32], and writes 0 into w[32]
Thread T(24, 33) compares x[24] and x[33], and writes 0 into w[33]
Thread T(24, 34) compares x[24] and x[34], and writes 0 into w[34]
Thread T(24, 35) compares x[24] and x[35], and writes 0 into w[35]
Thread T(24, 36) compares x[24] and x[36], and writes 0 into w[36]
Thread T(24, 37) compares x[24] and x[37], and writes 0 into w[37]
Thread T(24, 38) compares x[24] and x[38], and writes 0 into w[38]
Thread T(24, 39) compares x[24] and x[39], and writes 0 into w[39]
Thread T(24, 40) compares x[24] and x[40], and writes 0 into w[40]
Thread T(24, 41) compares x[24] and x[41], and writes 0 into w[41]
Thread T(24, 42) compares x[24] and x[42], and writes 0 into w[42]
Thread T(24, 43) compares x[24] and x[43], and writes 0 into w[43]
Thread T(24, 44) compares x[24] and x[44], and writes 0 into w[44]
Thread T(24, 45) compares x[24] and x[45], and writes 0 into w[45]
Thread T(24, 46) compares x[24] and x[46], and writes 0 into w[46]
Thread T(24, 47) compares x[24] and x[47], and writes 0 into w[47]
Thread T(24, 48) compares x[24] and x[48], and writes 0 into w[48]
Thread T(24, 49) compares x[24] and x[49], and writes 0 into w[49]
After step 2
W = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Maximum = 100
Location = 24


real	0m0.005s
user	0m0.000s
sys	0m0.004s

O tempo reduziu! Ainda que q2wt seja menor, a diferen�a de execu��o com q2 foi menor que 4x. Portanto, apesar de threads paralelizar a execu��o do c�digo, uma otimiza��o � usar de uma quantidade menor de threads, afim de mensurar quando o tempo de cria��o de threads otimiza a execu��o.
