#include <iostream>
#include <cstdlib>      /* srand, rand */
#include <ctime>       /* time */
#include <mpi.h>

#include "SuperSet.h"				// include definition of class Average

int main(int argc, char* argv[])
{
	int	provided;
	// Initialize the MPI environment.
	MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED, &provided);
	if (provided < MPI_THREAD_FUNNELED)
	       MPI_Abort(MPI_COMM_WORLD, 1);

	// Get the rank of the process
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	if (argc == 4) {
		std::size_t	vector_length = std::atoi(argv[1]);
		std::size_t	number_of_iterations = std::atoi(argv[2]);
		std::size_t	number_of_elements = std::atoi(argv[3]);
		/* initialize random seed: */
		std::srand(std::time(NULL));
		
		SuperSet	supersetobj(vector_length,number_of_iterations,number_of_elements);
		auto	average = supersetobj.computeSuperSetAverage();
		if (world_rank == 0)
			std::cout << "Average is: " << average << "\n";

		MPI_Barrier(MPI_COMM_WORLD);
		return 0;
	}
	else if (argc == 5) {
		std::size_t	vector_length = std::atoi(argv[1]);
		std::size_t	number_of_iterations = std::atoi(argv[2]);
		std::size_t	number_of_elements = std::atoi(argv[3]);
		double		test_value = std::atof(argv[4]);
		/* initialize random seed: */
		std::srand(std::time(NULL));
		std::vector<double>	vec(vector_length,test_value);
		
		SuperSet	supersetobj(vector_length,number_of_iterations,number_of_elements,vec);
		auto	average = supersetobj.computeSuperSetAverage();
		if (world_rank == 0)
			std::cout << "Average is: " << average << "\n";

		MPI_Barrier(MPI_COMM_WORLD);
		return 0;
	}
	else {
		// Tell the user how to run the program
		if (world_rank == 0) {
			std::cerr << "\nUsage: " << argv[0] << " vector_length number_of_iterations number_of_elements" << std::endl;
			std::cerr << "\nOr usage: " << argv[0] << " vector_length number_of_iterations number_of_elements test_value" << std::endl;
			std::cerr << "\nvector_length: tests memory capacity \n\nnumber_of_iterations: tests parallelization capacity" << std::endl;
			std::cerr << "\nnumber_of_elements: tests parallelization and memory capacities" << std::endl;
			std::cerr << "\nand optional test_value: tests  correct computation" << std::endl;
		}
		return 1;
	}

	// Finalize the MPI environment.
	MPI_Finalize();
}
