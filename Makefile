Test: main.o Sum.o Average.o Set.o SuperSet.o Timer.o
	mpicc -cc=g++-5 -fopenmp -Wall -pedantic -std=c++11 main.o Sum.o Average.o Set.o SuperSet.o Timer.o -o Test

main.o: main.cpp
	mpicc -cc=g++-5 -c -fopenmp -Wall -pedantic -std=c++11 main.cpp

Sum.o: Sum.cpp Sum.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++11 Sum.cpp

Average.o: Average.cpp Average.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++11 Average.cpp

Set.o: Set.cpp Set.h 
	g++-5 -c -fopenmp -Wall -pedantic -std=c++11 Set.cpp
	
SuperSet.o: SuperSet.cpp SuperSet.h 
	mpicc -cc=g++-5 -c -fopenmp -Wall -pedantic -std=c++11 SuperSet.cpp

Timer.o: Timer.cxx Timer.h TimerC.h
	mpicc -cc=g++-5 -c -fopenmp -Wall -pedantic -std=c++11 Timer.cxx

clean:
	rm -f Test *.o
