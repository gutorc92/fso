## Backup

Foi requisitado uma cópia de backup do arquivo tal que fosse possível ver as alterações realizadas nos items posteriores. Logo, os metadados devem ser preservados. Para tal a solução mais evidente seria copiar o arquivo modificando o a extensão para .bkp, como mostrado abaixo:

$ ./prog image_test.jpg DDMMAAAA
File name: image_test.jpg
Date passed: DDMMAAAA

Modified in Sun Sep  4 19:53:10 2016

Last acess in Thu Oct 20 03:20:24 2016

$ cp image_test.jpg image_test.bkp
$ ./prog image_test.bkp DDMMAAAA
File name: image_test.bkp
Date passed: DDMMAAAA

Modified in Thu Oct 20 19:23:16 2016

Last acess in Thu Oct 20 19:23:17 2016

Como ilustrado acima, os metadados são alterados, o que não satisfaz a condição. Portanto fomos consultar em cp --help, e existe uma flag(-p) que preserva esses dados. Logo a solução irá utilizar essa flag para fazer o backup.


## Data de criação

Segundo vários tópicos da web, colocados como referência abaixo, o padrão POSIX define apenas três datas diferentes para serem salvas: Data de acesso, ultima modificação e a ultima modificação dos metadados do arquivo. Nos modernos sistemas de arquivos do Linux, como ext4, usado nesse experimento, a informação de data de criação é mantida, porém o sistema operacional Linux não provê nenhuma forma de se recuperar isso. Pesquisando mais a fundo sobre o porque essa data não estar disponível, encontramos algumas respostas do mantenedor principal Linus Torvalds sobre essa informação:

> The nice thing about this is also that if this is supposed
> to be fully usable for Windows clients, the birthtime needs
> to be changeable. That's what NTFS semantics gives you, thus
> Windows clients tend to require it.

Ok. So it's not really a creation date, exactly the same way ctime
isn't at all a creation date.

And maybe that actually hints at a better solution: maybe a better
model is to create a new per-thread flag that says "do ctime updates
the way windows does them".

So instead of adding another "btime" - which isn't actually what even
windows does - just admit that the _real_ issue is that Unix and
Windows semantics are different for the pre-existing "ctime".

The fact is, windows has "access time", "modification time" and
"creation time" _exactly_ like UNIX. It's just that the ctime has
slightly different semantics in windows vs unix. So quite frankly,
it's totally insane to introduce a "birthtime", when that isn't even
what windows wants, just because people cannot face the actual real
difference.

Tell me why we shouldn't just do this right?

Outro email:
http://lwn.net/Articles/397445/

Logo, pela visão de Linus, o seu SO não deve prover algo simplesmente por que o windows prove e o recurso ctime(do padrão POSIX) é e deve ser semanticamente diferente nesses SOs. Alguns contribuidores importantes parecem discordar de Linus, como em http://lwn.net/Articles/397448/, tal que foi criada uma issue para uma extensão de stat: xstat(http://lwn.net/Articles/394279/) que manipula dentre outras informações, a data de criação de um arquivo.

Logo, pelo SO seria dificil achar essa informação. Mas foi navegando em foruns, que ouvimos falar de uma aplicação chamada debugfs(debug filesystem), presente por default na distro Linux utilizada. Ao visualizar o manual do debugfs temos que o aplicativo tinha suporte para sistemas de arquivo ext2, ext3 e ext4. Como visto em outros tópicos citados acima, esses sistemas de arquivos possuem a data de criação armazenada, ela se chama crtime. Através de múltiplos tópicos, achamos o seguinte:

http://askubuntu.com/questions/470134/how-to-find-the-creation-time-of-a-file

Reproduzindo os passos recebemos uma data chamada crtime, para testa-la, foi usado o commando touch no arquivo, então ao reexecutar o experimento, a data permaneceu, enquanto ctime, atime e mtime foram modificadas.

## Atualizando datas
touch -amt 0711171533 image_test.jpg
sudo debugfs -R 'stat /kuwener/workspaces/C/fso/trabalho4/q1/image_test.jpg' $DIR_DISK | grep crtime

## Referências

http://unix.stackexchange.com/questions/91197/how-to-find-creation-date-of-file

http://lwn.net/Articles/397442/
