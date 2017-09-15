//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//				Author:		Dematties Dario Jesus						//
//				Contact:	dariodematties@hotmail.com.ar					//
//						dariodematties@yahoo.com.ar					//
//						dario.dematties@frm.utn.edu.ar					//
//				Project:	Engineering PhD Project						//
//				Institution:	Universidad de Buenos Aires					//
//						Facultad de Ingeniería (FIUBA)					//
//				Workplace:	Instituto de Ingeniería						//
//						Biomédica FIUBA	&						//
//						CCT CONICET Mendoza INCIHUSA					//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// File Name:		SuperSet.cpp
// File Description:	SuperSet member-function definitions. This file contains implementations of the
//			member functions prototyped in SuperSet.h.

#include <mpi.h>
#include <omp.h>
#include <cassert>

#include "SuperSet.h"

using namespace std;

// constructor that initializes SuperSet
SuperSet::SuperSet( const std::size_t dimensionality,
		    const std::size_t iterations,
		    const std::size_t numberOfElements )
{
	int	auxiliary;
	_numberOfSets = numberOfElements;

	// Get the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_size = auxiliary;

	// Get the rank of the process
	MPI_Comm_rank(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_rank = auxiliary;

	// There must be -at least- as many sets as processes
	assert(_numberOfSets >= world_size);

	for ( std::size_t element = world_rank; element < _numberOfSets; element=element+world_size )
		_setsVector.push_back(Set(dimensionality,iterations,numberOfElements));

	_setsVector.shrink_to_fit();
} // end SuperSet constructor


// constructor that initializes SuperSet
SuperSet::SuperSet( const std::size_t dimensionality,
		    const std::size_t iterations,
		    const std::size_t numberOfElements,
		    const std::vector<double>& vec )
{
	int	auxiliary;
	_numberOfSets = numberOfElements;

	// Get the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_size = auxiliary;

	// Get the rank of the process
	MPI_Comm_rank(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_rank = auxiliary;

	// There must be -at least- as many sets as processes
	assert(_numberOfSets >= world_size);

	for ( std::size_t element = world_rank; element < _numberOfSets; element=element+world_size )
		_setsVector.push_back(Set(dimensionality,iterations,numberOfElements,vec));

	_setsVector.shrink_to_fit();
} // end SuperSet constructor


// computes the averages in SuperSet
double	SuperSet::computeSuperSetAverage()
{
	double	output = 0.0;
	#pragma omp parallel for default(none) shared(output)
	for ( std::size_t element = 0; element < _setsVector.size(); element++ ) {
		auto	partial = _setsVector[element].computeSetAverage();	
		#pragma omp critical
			output += partial;
	}

	output = output/(double)_setsVector.size();

	// Begin Inter-process comunication
	//
	int	auxiliary;
	// Get the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_size = auxiliary;

	// Get the rank of the process
	MPI_Comm_rank(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_rank = auxiliary;

	if (world_rank != 0) { // Any process has to send its computation to process 0
		MPI_Send(&output, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
       	else { // Process 0 receives all processes computations
		for ( std::size_t process = 1; process < world_size; process++ ) {
			double	number;
			MPI_Recv(&number, 1, MPI_DOUBLE, process, 0, MPI_COMM_WORLD,
				 MPI_STATUS_IGNORE);
			output+=number;
		}
		output = output/(double)world_size;
	}
	//
	// End Inter-process comunication
	
	return	output;
} // end function computeSuperSetAverage

