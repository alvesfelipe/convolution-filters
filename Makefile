all:
	g++ -I /usr/local/include/opencv2/ -I include/ src/*.cpp -L /usr/local/lib `pkg-config --cflags --libs opencv` -o trabalho2.out