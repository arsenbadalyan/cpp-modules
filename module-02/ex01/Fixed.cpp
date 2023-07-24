#include "Fixed.hpp"

const int Fixed::m_frac = 8;

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->m_fixed = 0;
}

Fixed::Fixed( const int num )
{
    std::cout << "Int constructor called" << std::endl;
    this->m_fixed = (num << Fixed::m_frac);
}

Fixed::Fixed( const float num )
{
    std::cout << "Float constructor called" << std::endl;
    this->m_fixed = roundf((num * (1 << Fixed::m_frac)));
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->m_fixed = other.m_fixed;
    return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& other )
{
    os << other.toFloat();
    return os;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->m_fixed);
}

void Fixed::setRawBits( const int newFixed )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->m_fixed = newFixed;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->m_fixed / (1 << Fixed::m_frac));
}

int Fixed::toInt( void ) const
{
    return (this->m_fixed >> Fixed::m_frac);
}
