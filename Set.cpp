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

// File Name:		Set.cpp
// File Description:	Set member-function definitions. This file contains implementations of the
//			member functions prototyped in Set.h.

#include <omp.h>

#include "Set.h"

using namespace std;

// constructor that initializes Set
Set::Set( const std::size_t dimensionality,
	  const std::size_t iterations,
	  const std::size_t numberOfElements )
{
	_numberOfElements = numberOfElements;
	for ( std::size_t element = 0; element < _numberOfElements; element++ )
		_averagesVector.push_back(Average(dimensionality,iterations));

} // end Set constructor


// constructor that initializes Set
Set::Set( const std::size_t dimensionality,
	  const std::size_t iterations,
	  const std::size_t numberOfElements,
	  const std::vector<double>& vec )
{
	_numberOfElements = numberOfElements;
	for ( std::size_t element = 0; element < _numberOfElements; element++ )
		_averagesVector.push_back(Average(dimensionality,iterations,vec));

} // end Set constructor


// computes the averages in Set
double	Set::computeSetAverage()
{
	double	output = 0.0;
	#pragma omp parallel for default(none) shared(output)
	for ( std::size_t element = 0; element < _numberOfElements; element++ ) {
		auto	partial = _averagesVector[element].computeAverage();	
		#pragma omp critical
			output += partial;
	}

	return	output/(double)_numberOfElements;
} // end function computeSetAverage

