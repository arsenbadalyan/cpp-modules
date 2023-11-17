#include <iostream>
#include "Array.hpp"

int main( int, char ** )
{
    Array<int> numbers(5);
    unsigned int size = numbers.size();

    for (unsigned int i = 0; i < size; i++)
    {
        numbers[i] = (i + (i * 2)) / 2;
        std::cout << "array[" << i << "] = " << numbers[i] << std::endl;
    }

    return (0);
}