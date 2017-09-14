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

// File Name:		Average.h
// File Description:	Average class definition. This file presents Average' public
//			interface without revealing the implementations of Average' member functions,
//			which are defined in Average.cpp.


// Average class derived from class Sum through inheritance.
// Class Description: This class inherits Sum class and computes average
 
#ifndef AVERAGE_H
#define AVERAGE_H

#include "Sum.h"						// Sum class declaration

class Average : public Sum
{
public:
		Average( const std::size_t,
		    	 const std::size_t );					// constructor that initializes internal vectors randomly

		Average( const std::size_t,
		    	 const std::size_t,
			 const std::vector<double>& );			// constructor that initializes internal vectors with values from external data

	double	computeAverage();						// computes average from sum of internal vector values 

}; // end class Average

#endif

