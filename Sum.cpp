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

// File Name:		Sum.cpp
// File Description:	Sum member-function definitions. This file contains implementations of the
//			member functions prototyped in Sum.h.

#include <omp.h>
#include <cstdlib>      /* srand, rand */
#include <cassert>

#include "Sum.h"				// include definition of class Sum

using namespace std;

// constructor that initializes internal vector elements at random
Sum::Sum( const std::size_t dimensionality )
{
	_dimensionality = dimensionality;
	_internalVector.resize(_dimensionality);

	for ( std::size_t dim = 0; dim < _dimensionality; dim++ )
		_internalVector[dim] = ((double) std::rand() / (RAND_MAX));		// generate secret number between 0 and 1
} // end Sum constructor


// constructor that initializes internal vector elements from external data 
Sum::Sum( const std::size_t dimensionality,
		  const std::vector<double>& vec )
{
	assert(dimensionality == vec.size());
	_dimensionality = dimensionality;
	_internalVector.resize(_dimensionality);

	for ( std::size_t dim = 0; dim < _dimensionality; dim++ )
		_internalVector[dim] = vec[dim];				// generate secret number between 0 and 1
} // end Sum constructor


// function to modify the synapticWeights matrix throught the use of the Kohonen's learning rule
double	Sum::computeSum()
{
	double	accumulator = 0.0;
	#pragma omp parallel for default(none) shared(accumulator)
	for ( std::size_t dim = 0; dim < _dimensionality; dim++ )		// the index dim corresponds to the internal vector element
		accumulator += _internalVector[dim];

	return	accumulator;
} // end function learningRule


