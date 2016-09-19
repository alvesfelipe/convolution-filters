# Segundo Projeto de PDI

O projeto tem como objetivo o desenvolvimento e aplicação de filtros, utilizando máscaras convolucionais de dimensões MxN aplicadas a imagens de dimensões MxN.

### Versão
1.0

### Dependências

O projeto tem como dependência a biblioteca OpenCV, que pode ser instalada a partir das instruções abaixo:

```sh
$ sudo apt-get install build-essential checkinstall cmake pkg-config yasm
$ git clone https://github.com/opencv/opencv.git
$ cd opencv
$ mkdir release
$ cd release
$ cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_PYTHON_SUPPORT=ON ..
$ make && sudo make install
```
Para definição das variáveis de ambiente você pode executar:

```sh
$ export LD_LIBRARY_PATH=/usr/local/lib
```
ou, para não precisar executar o comando acima, sempre que uma nova instância do terminal for aberta, podemos adicionar o PATH ao seguinte arquivo de configuração:

```sh
$ subl /etc/ld.so.conf
$ add line /usr/local/lib
$ sudo ldconfig
```
### Execução

Instaladas as dependências, podemos compilar e executar o código a partir dos seguites comandos:

```sh
$ make
$ ./trabalho2.out files/cameraman.jpg files/b2.csv
```
