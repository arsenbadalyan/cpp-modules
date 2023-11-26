#include "BitcoinExchange.hpp"

int main( int, char ** )
{
    try {
        BitcoinExchange::validateDB();
    } catch (const std::exception & exc) {
        std::cout << exc.what() << std::endl;
    }
    return (0);
}