#include "PmergeMe.hpp"

int main( int argc, char ** argv ) {

	try {
		if (argc < 2)
			throw std::runtime_error(ERR_INVALID_ARGS);
		argv++;
		PmergeMe::FJMI(argv);
	} catch ( const std::exception & exc ) {
		std::cout << "Error: " << exc.what() << std::endl;
		return (1);
	}

	return (0);
}