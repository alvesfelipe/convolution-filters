all:
	g++ -I /usr/local/include/ -L /usr/local/lib -I include/ src/*.cpp `pkg-config --cflags --libs opencv` -o trabalho2.out