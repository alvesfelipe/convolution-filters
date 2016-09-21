all:
<<<<<<< Updated upstream
	g++ -I /usr/local/include/ -L /usr/local/lib -I include/ src/*.cpp `pkg-config --cflags --libs opencv` -o trabalho2.out
=======
	g++-5 -I /usr/local/include/ -L /usr/local/lib -I include/ src/*.cpp -std=c++11 `pkg-config --cflags --libs opencv` -o trabalho2.out
>>>>>>> Stashed changes
