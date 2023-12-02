#include <iostream>
#include "RPN.hpp"

int main( int argc, char** argv ) {
    try {
        if (argc != 2)
            throw std::runtime_error(ERR_WRONG_ARG_LIST);
        RPN::executeExpression(argv[1]);
    } catch( const std::exception & exc ) {
        std::cout << "Error: " << exc.what() << std::endl;
    }
    return (0);
}