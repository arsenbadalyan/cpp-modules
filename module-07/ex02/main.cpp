#include <iostream>
#include "Array.hpp"

int main( int, char ** )
{
    Array<int> numbers(5);
    unsigned int size = numbers.size();

    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << i << std::endl;
        numbers[i] = i;
        std::cout << numbers[i] << std::endl;
    }
    std::cout << numbers;
    return (0);
}