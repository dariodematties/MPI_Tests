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

// File Name:		Sum.h
// File Description:	Sum class definition. This file presents Sum's public
//			interface without revealing the implementations of Sum's member functions,
//			which are defined in Sum.cpp.


// Class Description: This class computes the sum of values stored in a vector 

#ifndef SUM_H
#define SUM_H

#include <vector>

class Sum
{
public:
		Sum( const std::size_t );						// constructor that initializes object of class Sum
		
		Sum( const std::size_t,
		     const std::vector<double>& );					// constructor that initializes object of class Sum
											// with external values

	double	computeSum();								// function that computes the sum

private:
	std::size_t				_dimensionality;			// flat dimensionality of the internal vector
	std::vector<double>			_internalVector;			// internal vector 
}; // end class Sum

#endif



