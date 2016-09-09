# Arquivos
	q03a.c - primeira versão requisitada pelo sistema
	q03b.c - segunda versão requisitada pelo sistema
	q03c.c - terceira versão requisitada pelo sistema
	operations.h - funções usadas por todas as respostas 
	operations.c - impelementacão das funções
	generate_matriz.py - arquivo python para gerar matrizes
	test - shell script para rodar toas as versões com as mesmas matrizes
	test_time - exibe apenas o tempo levado para executar
	test_mul - executa 15 testes de uma única vez usando o arquivo test
	Makefile - arquivo para copilar os arquivos
	matrixs - diretório contendo matrizes para teste

# Dependências
	Para usar os arquivos de testes é necessários utilizar a biblioteca
	python chamada numpy. Para instalar essa biblioteca é necessário
	apenas utilizar o comando:
		pip install numpy

# Copilar
	Para copilar os arquivo é necessário apenas usar o comando make

# Executar
	Para executar uma das impelementacoes basta executar o seguinte
	comando na linha de comando:

	./{implementacao} {op} arquivo_para_matriz arquivo_para_matriz

	Legenda:
		implementação: executável da questão, pode ser a b c.
		op: opção de saída(g - para a matriz resultado e t para o tempo)
		arquivo_para_matriz: arquivo para a matriz que se deseja fazer
							 a multiplicação.

	Os arquivos com as matrizes deve ter na sua primeira linha o número
	de linhas e depois o número de colunas. Nas próximas linhas devem
	estar os números da matriz obedecendo o número de colunas e linhas
	declarado.

	O diretório matrixs contém várias matrizes que podem ser usadas
	para testes manuais. 
	

# Testes
	Para executar o arquivo de teste bastar utilizar o comando
		./test linhas colunas

	O número de linhas e colunas devem ser iguais por razões de implmentação.
	
	Para verificar o temo levado por cada matriz apenas execute:
		./test_time linhas colunas

	A restrição de linhas e colunas é valida para esse caso também.

	
# Resultados
