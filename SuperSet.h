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

// File Name:		SuperSet.h
// File Description:	SuperSet class definition. This file presents SuperSet's public
//			interface without revealing the implementations of SuperSet's member functions,
//			which are defined in SuperSet.cpp.


// Class Description: ...

#ifndef SUPER_SET_H
#define SUPER_SET_H

#include "Set.h"

class SuperSet
{
public:

		SuperSet( const std::size_t,
		     const std::size_t,
		     const std::size_t ); 				// SuperSet constructor, which initializes internal vectors at random

		SuperSet( const std::size_t,
		     const std::size_t,
		     const std::size_t,
		     const std::vector<double>& ); 			// SuperSet constructor, which initializes internal vetors from external data

	double	computeSuperSetAverage();					// computes averages in all the set
	
private:
	std::size_t			_numberOfSets;
	std::vector<Set>		_setsVector;

}; // end class SuperSet

#endif

