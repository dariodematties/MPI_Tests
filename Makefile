# Set the compilers you want to use

# Use g++-5 gcc version 4.8.5 (Ubuntu 4.8.5-2ubuntu1~14.04.1)
CC = g++

# Use Intel C++ compiler
#CC = icpc


# Use mpicc mpicc for MPICH version 3.2
MPI = mpicc

# Use mpiicc if you us Intel compilers
#MPI = mpiicc


# Use the following Compile-time flags
CFLAGS = -O3 -fopenmp -Wall -pedantic -std=c++11

Test: main.o Sum.o Average.o Set.o SuperSet.o Timer.o
	$(MPI) -cc=$(CC) $(CFLAGS) main.o Sum.o Average.o\
					  Set.o SuperSet.o Timer.o -o Test

main.o: main.cpp
	$(MPI) -cc=$(CC) -c $(CFLAGS) main.cpp

Sum.o: Sum.cpp Sum.h 
	$(CC) -c $(CFLAGS) Sum.cpp

Average.o: Average.cpp Average.h 
	$(CC) -c $(CFLAGS) Average.cpp

Set.o: Set.cpp Set.h 
	$(CC) -c $(CFLAGS) Set.cpp
	
SuperSet.o: SuperSet.cpp SuperSet.h 
	$(MPI) -cc=$(CC) -c $(CFLAGS) SuperSet.cpp

Timer.o: Timer.cxx Timer.h TimerC.h
	$(MPI) -cc=$(CC) -c $(CFLAGS) Timer.cxx

clean:
	rm -f Test *.o
