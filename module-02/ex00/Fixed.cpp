#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed = 0;
}

Fixed::Fixed(Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed = obj.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed);
}

void Fixed::setRawBits(const int newFixed)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed = newFixed;
}
