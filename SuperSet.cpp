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

#include "Timer.h"
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
	double	local_sum = 0.0, output;

	timer::MarkStartEvent("SuperSet::computeSuperSetAverage  computation");
	#pragma omp parallel for default(none) shared(local_sum)
	for ( std::size_t element = 0; element < _setsVector.size(); element++ ) {
		auto	partial = _setsVector[element].computeSetAverage();	
		#pragma omp critical
			local_sum += partial;
	}

	local_sum = local_sum/(double)_setsVector.size();
 	timer::MarkEndEvent("SuperSet::computeSuperSetAverage  computation");

	// Begin Inter-process comunication
	//
	timer::MarkStartEvent("SuperSet::computeSuperSetAverage Inter-process comunication");
	int	auxiliary;
	double	global_sum = 0.0;

	// Get the number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &auxiliary);
	std::size_t	world_size = auxiliary;

	// Reduce all of the local sums into the global sum
	MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0,
		   MPI_COMM_WORLD);

	output = global_sum/(double)world_size;

 	timer::MarkEndEvent("SuperSet::computeSuperSetAverage Inter-process comunication");
	//
	// End Inter-process comunication
	
	MPI_Barrier(MPI_COMM_WORLD);
	return	output;
} // end function computeSuperSetAverage

