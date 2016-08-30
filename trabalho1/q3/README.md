<b>Pergunta:</b> O valor impresso decorrente do enunciado que contempla o item anterior é igual ao valor do endereço gravado em dPtr?<br>
<b>Resposta:</b> Não, pois dPtr tem endereço próprio, e o item anterior está aprontando para outra variavel, no caso, number2

<b>Pergunta:</b> A execução do item anterior pode provocar algum erro em tempo de execução?
<b>Resposta:</b> Alguns. Primeiramente, se a região de alocação das string estiverem preenchidas, uma vez que o vetor não foi inicializado, ele irá colocar valores indesejaveis o que pode ocasionar em estouro de vetor, uma vez que cada string permite 100 chars, supondo que s1 seja iniciado com mais de 50 caracteres, ele irá lançar um erro em tempo de execução.
