#include <iostream>
#include "PhoneBook.hpp"

static const std::string ADD = "ADD";
static const std::string SEARCH = "SEARCH";
static const std::string EXIT = "EXIT";

void PhoneBook::add(void) {
    std::string input;

    std::cout << "Contact Info:" << std::endl;
    std::cout << "Enter First Name: ";
    // getline(std::cin, input);
    
}

void PhoneBook::search(void) {

}

void PhoneBook::processInput(void) {
    std::string input;

    while (1) {
        std::cout << "Please type one of commands: [ADD] | [SEARCH] | [EXIT]" << std::endl;
        std::cout << "Your input: ";
        getline(std::cin, input);
        // if (input == ::EXIT)
        //     return ;
        // if (input == ::ADD)
        //     add();
        // if (input == ::SEARCH)
        //     search();
    }
    return ;
}