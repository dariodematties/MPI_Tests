Test: main.o Sum.o 
	g++-5 -fopenmp -Wall -pedantic -std=c++14 main.o Sum.o -o Test

main.o: main.cpp
	g++-5 -c -fopenmp -Wall -pedantic -std=c++14 main.cpp

Sum.o: Sum.cpp Sum.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++14 Sum.cpp

clean:
	rm *.o Test
