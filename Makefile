Test: main.o Sum.o Average.o Set.o
	g++-5 -fopenmp -Wall -pedantic -std=c++14 main.o Sum.o Average.o Set.o -o Test

main.o: main.cpp
	g++-5 -c -fopenmp -Wall -pedantic -std=c++14 main.cpp

Sum.o: Sum.cpp Sum.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++14 Sum.cpp

Average.o: Average.cpp Average.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++14 Average.cpp

Set.o: Set.cpp Set.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++14 Set.cpp

clean:
	rm *.o Test
