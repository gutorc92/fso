# Shared Library

Para compilar uma biblioteca dinâmica(ou compartilhada), é necessário seguir alguns passos que estão detalhadamente descritos no livro Advanced Linux Programming. Tutorial de compilação dos arquivos dessa pasta está no arquivo documentation.html.

# Questões

* Em relação ao programa que contempla os itens a) e b), quais foram as alterações de códigos-fonte necessárias para a solução (se houverem)?

Nenhuma alteração de código fonte, toda diferença entre ambos se resume na forma de compilação, na biblioteca dinâmica o executável final não possui o código da biblioteca compartilhada, invés disso ela é simplesmente referenciada.

* Dados os conhecimentos adquiridos em função desse trabalho, indique vantagens e problemas decorrentes da utilização de bibliotecas dinâmicas.

Uma das grandes vantagens é a modularização, fazendo com que uma vez que seja criada uma biblioteca dinâmica, vários executáveis referenciem esse mesmo código. Uma das grandes desvantagens disso é em contrapartida o mal funcionamento dos executáveis quando essas bibliotecas são modificadas(atualizadas, removidas). A localização das bibliotecas pode ser problematica também, por isso é bom existir um padrão de localidade para cada biblioteca compartilhada.
