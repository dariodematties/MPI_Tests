#include <iostream>
#include <cstdlib>      /* srand, rand */
#include <ctime>       /* time */

#include "Average.h"				// include definition of class Average

int main(int argc, char* argv[])
{
	if (argc == 3) {
		std::size_t	vector_length = std::atoi(argv[1]);
		std::size_t	number_of_iterations = std::atoi(argv[2]);
		/* initialize random seed: */
		std::srand(std::time(NULL));
		
		Average	averageobj(vector_length,number_of_iterations);
		auto	average = averageobj.computeAverage();
		std::cout << "Average is: " << average << "\n";
	}
	else if (argc == 4) {
		std::size_t	vector_length = std::atoi(argv[1]);
		std::size_t	number_of_iterations = std::atoi(argv[2]);
		double		test_value = std::atof(argv[3]);
		/* initialize random seed: */
		std::srand(std::time(NULL));
		std::vector<double>	vec(vector_length,test_value);
		
		Average	averageobj(vector_length,number_of_iterations,vec);
		auto	average = averageobj.computeAverage();
		std::cout << "Average is: " << average << "\n";
	}
	else {
		// Tell the user how to run the program
		std::cerr << "Usage: " << argv[0] << " vector_length number_of_iterations" << std::endl;
		std::cerr << "Or usage: " << argv[0] << " vector_length number_of_iterations test_value" << std::endl;
		std::cerr << "vector_length: test memory capacity \nnumber_of_iterations: test the parallelization capacity" << std::endl;
		std::cerr << "and optional test_value: test the correct computation" << std::endl;
		return 1;
	}
}
