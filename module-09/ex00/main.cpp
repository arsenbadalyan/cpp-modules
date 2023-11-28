#include "BitcoinExchange.hpp"

int main( int argc, char ** argv )
{
    try {

        if (argc != 2)
            throw std::runtime_error(ERR_WRONG_ARG);

        BitcoinExchange::validateDB();
		BitcoinExchange::executeInput(argv[1]);
    } catch (const std::exception & exc) {
        std::cout << exc.what() << std::endl;
        return (1);
    }
    return (0);
}