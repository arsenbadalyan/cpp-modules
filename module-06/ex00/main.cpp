#include <iostream>
#include "validator.hpp"

int main( int argc, char ** userInput ) {
    try {
        validator(argc, userInput);
    } catch (std::exception *exc) {
        std::cout << exc->what() << std::endl;
    }
    return (0);
}