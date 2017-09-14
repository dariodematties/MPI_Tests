#include <iostream>
#include <cstdlib>      /* srand, rand */
#include <ctime>       /* time */

#include "Average.h"				// include definition of class Average

int main(int argc, char* argv[])
{
	// Check the number of parameters
	if (argc != 3) {
		// Tell the user how to run the program
		std::cerr << "Usage: " << argv[0] << " vector_length number_of_iterations" << std::endl;
		return 1;
	}

	std::size_t	vector_length = std::atoi(argv[1]);
	std::size_t	number_of_iterations = std::atoi(argv[2]);
	/* initialize random seed: */
	std::srand(std::time(NULL));
	
	Average	averageobj(vector_length,number_of_iterations);
	auto	average = averageobj.computeSum();
	std::cout << "Average is: " << average << "\n";
}
