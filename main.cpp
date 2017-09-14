#include <iostream>
#include <cstdlib>      /* srand, rand */
#include <ctime>       /* time */

#include "Set.h"				// include definition of class Average

int main(int argc, char* argv[])
{
	if (argc == 4) {
		std::size_t	vector_length = std::atoi(argv[1]);
		std::size_t	number_of_iterations = std::atoi(argv[2]);
		std::size_t	number_of_elements = std::atoi(argv[3]);
		/* initialize random seed: */
		std::srand(std::time(NULL));
		
		Set	setobj(vector_length,number_of_iterations,number_of_elements);
		auto	average = setobj.computeSetAverage();
		std::cout << "Average is: " << average << "\n";
	}
	else if (argc == 5) {
		std::size_t	vector_length = std::atoi(argv[1]);
		std::size_t	number_of_iterations = std::atoi(argv[2]);
		std::size_t	number_of_elements = std::atoi(argv[3]);
		double		test_value = std::atof(argv[4]);
		/* initialize random seed: */
		std::srand(std::time(NULL));
		std::vector<double>	vec(vector_length,test_value);
		
		Set	setobj(vector_length,number_of_iterations,number_of_elements,vec);
		auto	average = setobj.computeSetAverage();
		std::cout << "Average is: " << average << "\n";
	}
	else {
		// Tell the user how to run the program
		std::cerr << "Usage: " << argv[0] << " vector_length number_of_iterations number_of_elements" << std::endl;
		std::cerr << "Or usage: " << argv[0] << " vector_length number_of_iterations number_of_elements test_value" << std::endl;
		std::cerr << "vector_length: tests memory capacity \nnumber_of_iterations: tests parallelization capacity" << std::endl;
		std::cerr << "number_of_elements: tests parallelization and memory capacities" << std::endl;
		std::cerr << "and optional test_value: tests  correct computation" << std::endl;
		return 1;
	}
}
