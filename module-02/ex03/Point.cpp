#include "Point.hpp"

// --------------------- Constructors, destructor
Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const Point& other ) : _x(other._x), _y(other._y) {}

Point::Point( const float x, const float y ) : _x(x), _y(y) {}

Point::~Point(){};

// ---------------- overloaded operators
Point& Point::operator=( const Point& other )
{
    (Fixed)this->_x = other._x;
    (Fixed)this->_y = other._y;
    return (*this);
}

// ---------- getters and setters

Fixed Point::getFixedValueX( void ) const
{
    return (this->_x);
}

Fixed Point::getFixedValueY( void ) const
{
    return (this->_y);
}