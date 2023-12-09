#include "PmergeMe.hpp"

int main( int argc, char ** argv ) {

	try {
		if (argc != 2)
			throw std::runtime_error(ERR_INVALID_ARGS);
		PmergeMe::FJMI(argv[1]);
	} catch ( const std::exception & exc ) {
		std::cout << "Error: " << exc.what() << std::endl;
	}

	return (0);
}