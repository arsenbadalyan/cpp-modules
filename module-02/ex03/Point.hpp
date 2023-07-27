#pragma once
#ifndef __POINT__HPP__
#define __POINT__HPP__

#include <iostream>
#include "Fixed.hpp"

class Point {
    public:
        // --------- constructor, destructor
        Point( void );
        Point( const Point& );
        Point( const float, const float );
        ~Point();

        // --------- overloaded operators
        Point& operator=(const Point&);

        // --------- getters and stters
        Fixed getFixedValueX( void ) const;
        Fixed getFixedValueY( void ) const;
    private:
        Fixed const _x;
        Fixed const _y;
};

bool bsp( Point const, Point const, Point const, Point const );

#endif // !__POINT__HPP__
