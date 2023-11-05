#include <iostream>
#include "validator.hpp"
#include "ScalarConverter.hpp"

int main( int argc, char ** userInput ) {
    try {
        validator(argc, userInput);
        ScalarConverter::convert(userInput[1]);
    } catch (std::exception & exc) {
        std::cout << exc.what() << std::endl;
    }
    return (0);
}