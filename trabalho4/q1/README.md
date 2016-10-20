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
