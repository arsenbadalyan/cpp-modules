#include "Point.hpp"
#include <iostream>

Point a(1, 0);
Point b(5, 5);
Point c(9, 0);

static void testWithThisXY( const float x, const float y )
{
    Point point(x, y);
    
    std::cout << "Is points (" << x << ", " << y <<  ") inside of triangle: ";
    bsp(a, b, c, point) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
}

int main( int, char** )
{
    testWithThisXY(3, 2);
    testWithThisXY(2, 2);
    testWithThisXY(9, 0);
    testWithThisXY(5, 5);
    return (0);
}
