all:
	g++ -I /usr/local/include/ -L /usr/local/lib -I include/ src/*.cpp -std=c++11 `pkg-config --cflags --libs opencv` -o trabalho2.out