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

// File Name:		Set.h
// File Description:	Set class definition. This file presents Set's public
//			interface without revealing the implementations of Set's member functions,
//			which are defined in Set.cpp.


// Class Description: ...

#ifndef SET_H
#define SET_H

#include "Average.h"

class Set
{
public:

		Set( const std::size_t,
		     const std::size_t,
		     const std::size_t ); 				// Set constructor, which initializes internal vectors at random

		Set( const std::size_t,
		     const std::size_t,
		     const std::size_t,
		     const std::vector<double>& ); 			// Set constructor, which initializes internal vetors from external data

	double	computeSetAverage();					// computes averages in all the set
	
private:
	std::size_t			_numberOfElements;
	std::vector<Average>		_averagesVector;

}; // end class Set

#endif

