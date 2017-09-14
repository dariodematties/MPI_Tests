#include <iostream>
#include <cstdlib>      /* srand, rand */
#include <ctime>       /* time */

#include "Sum.h"				// include definition of class Sum

int main(int argc, char* argv[])
{
	// Check the number of parameters
	if (argc != 2) {
		// Tell the user how to run the program
		std::cerr << "Usage: " << argv[0] << " vector_length" << std::endl;
		return 1;
	}

	std::size_t	vector_length = std::atoi(argv[1]);
	/* initialize random seed: */
	std::srand(std::time(NULL));
	
	Sum	sumobj(vector_length);
	auto	sum = sumobj.computeSum();
	std::cout << "Sum is: " << sum << "\n";
}
