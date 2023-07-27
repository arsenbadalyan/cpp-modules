#include <cmath>
#include "Point.hpp"

static Fixed module(Fixed num);
static Fixed calculateTriangleArea( Point const a, Point const b, Point const c );

static Fixed module(Fixed num)
{
    if (num < 0)
        return (num * -1);
    return (num);
}

static Fixed calculateTriangleArea( Point const a, Point const b, Point const c )
{
    return ((( a.getFixedValueX() * ( b.getFixedValueY() - c.getFixedValueY() )) +
             ( b.getFixedValueX() * ( c.getFixedValueY() - a.getFixedValueY() )) +
             ( c.getFixedValueX() * ( a.getFixedValueY() - b.getFixedValueY() ))) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed abcArea = module( calculateTriangleArea( a, b, c ) );
    Fixed pabArea = module( calculateTriangleArea( point, a, b ) );
    Fixed pbcArea = module( calculateTriangleArea( point, b, c ) );
    Fixed pacArea = module( calculateTriangleArea( point, a, c ) );

    // std::cout << abcArea << std::endl;
    // std::cout << pabArea << std::endl;
    // std::cout << pbcArea << std::endl;
    // std::cout << pacArea << std::endl;

    return ( abcArea == ( pabArea + pbcArea + pacArea )
                && pabArea != 0
                && pbcArea != 0
                && pacArea != 0 );
}
