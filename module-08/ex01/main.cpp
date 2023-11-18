#include <iostream>
#include "Span.hpp"

int main( int, char ** )
{
    try {
        Span span(10000);

        span.addNumber(-1);
        span.addNumber(132);
        span.addNumber(345);

        span.fill(9996); // if argument will be greater it will catch exception

        span.addNumber(424242);

        span.fill(0);

        std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span is: " << span.longestSpan() << std::endl;
    } catch (const std::exception& exc) {
        std::cout << "Error: " << exc.what() << std::endl;
    }
    return (0);
}