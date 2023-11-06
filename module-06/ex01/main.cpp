#include "Serializer.hpp"
#include <iostream>

int main( int, char ** ) {
    Data * dot = new Data;

    dot->x = 11;
    dot->y = 5;

    uintptr_t addressValue = Serializer::serialize(dot);
    Data * dotCopy = Serializer::deserialize(addressValue);

    std::cout << "Real dot address: " << dot << std::endl;
    std::cout << "Copy dot address: " << dotCopy << std::endl;

    return (0);
}