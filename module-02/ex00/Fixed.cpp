#include "Fixed.hpp"

const int Fixed::m_frac = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->m_fixed = 0;
}

Fixed::Fixed( Fixed& obj )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=( Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->m_fixed = other.getRawBits();
	return (*this);
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
