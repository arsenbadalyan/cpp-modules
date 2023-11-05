#include "validator.hpp"

bool hasNotAllowedChars( std::string userInput, size_t inputSize ) {
    size_t i = 0;
    bool hasDot = false;

    if (userInput[0] == '-' || userInput[0] == '+') {
        i++;
    }

    for (; i < inputSize; i++) {
        if (!std::isdigit(userInput[i]) && inputSize != 1) {
            if (userInput[i] == '.' && !hasDot
                && i > 0 && std::isdigit(userInput[i - 1])
                && i < inputSize - 1 && std::isdigit(userInput[i + 1])) {
                    hasDot = true;
                    continue ;
                }
            if (userInput[i] == 'f' && i == (inputSize - 1) && hasDot)
                continue ;
            if (userInput != "-inf" && userInput != "+inf"
                && userInput != "nan" && userInput != "-inff"
                && userInput != "+inff" && userInput != "nanf"
                && userInput != "inf" && userInput != "inff")
                return (true);
            break ;
        }
    }

    return (false);
}

void validator( int argc, char ** userInputC ) {

    if (argc != 2)
        throw std::runtime_error("Please input one argument of any type");
    
    std::string userInput = userInputC[1];
    size_t inputSize = userInput.length();

    if (!inputSize)
        throw std::runtime_error("There must me more then or one character");

    if (hasNotAllowedChars(userInput, inputSize))
        throw std::runtime_error("Please enter valid input described in subject");

}