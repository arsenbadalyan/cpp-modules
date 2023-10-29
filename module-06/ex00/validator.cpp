#include "validator.hpp"

int letterValidator( std::string userInput, size_t inputSize ) {
    int sign = 1;
    size_t i = 0;

    if (userInput[0] == '-' || userInput[0] == '+') {
        if (!inputSize)
            return (0);
        sign = '-' - userInput[0];
        sign -= 1;
        i++;
    }

    for (; i < inputSize; i++) {
        if (!std::isdigit(userInput[i]) && inputSize != 1) {
            if (userInput != "-inf" && userInput != "+inf"
                && userInput != "nan" && userInput != "-inff"
                && userInput != "+inff" && userInput != "nanf")
                return (0);
            break ;
        }
    }

    return (sign);
}

void validator( int argc, char ** userInputC ) {
    // size_t i = 0;
    int sign;

    if (argc != 2)
        throw std::runtime_error("Please input one argument of any type");
    
    std::string userInput = userInputC[1];
    size_t inputSize = userInput.length();

    if (!inputSize)
        throw std::runtime_error("There must me more then or one character");

    sign = letterValidator(userInput, inputSize);
    if (!sign)
        throw std::runtime_error("Please enter valid input described in subject");
    std::cout << "sign is - " << sign << std::endl;

}