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

// File Name:		Average.cpp
// File Description:	Average member-function definitions. This file contains implementations of the
//			member functions prototyped in Average.h.

#include "Average.h"				// includes definition of class Average

using namespace std;

// constructor initializes Average class object at random
Average::Average( const std::size_t dimensionality,
		  const std::size_t iterations )
	// explicitly call base-class constructor
	: Sum(dimensionality, iterations)
{
} // end Average constructor


// constructor initializes Average class object with external vector values
Average::Average( const std::size_t dimensionality,
		  const std::size_t iterations, 
		  const std::vector<double>& vec )
	// explicitly call base-class constructor
	: Sum(dimensionality, iterations, vec)
{
} // end Average constructor


// hence, it could contain a set of linking units as well as a unique linking unit.
double	Average::computeAverage()
{
	return	Sum::computeSum()/(double)_dimensionality;
} // end function computeAverage

