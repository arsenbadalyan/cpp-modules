#include "Fixed.hpp"

const int Fixed::m_frac = 8;

Fixed::Fixed( void )
{
    // std::cout << "Default constructor called" << std::endl;
    this->m_fixed = 0;
}

Fixed::Fixed( const int num )
{
    // std::cout << "Int constructor called" << std::endl;
    this->m_fixed = (num << Fixed::m_frac);
}

Fixed::Fixed( const float num )
{
    // std::cout << "Float constructor called" << std::endl;
    this->m_fixed = roundf((num * (1 << Fixed::m_frac)));
}

Fixed::Fixed( const Fixed& other )
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->m_fixed = other.m_fixed;
    return (*this);
}

std::ostream& operator<<( std::ostream& os, const Fixed& other )
{
    os << other.toFloat();
    return os;
}

// --------------------- Comparison functions

bool Fixed::operator<( const Fixed& other ) const
{
    return (this->m_fixed < other.m_fixed);
}

bool Fixed::operator>( const Fixed& other ) const
{
    return (this->m_fixed > other.m_fixed);
}

bool Fixed::operator<=( const Fixed& other ) const
{
    return (this->m_fixed <= other.m_fixed);
}

bool Fixed::operator>=( const Fixed& other ) const
{
    return (this->m_fixed >= other.m_fixed);
}

bool Fixed::operator==( const Fixed& other ) const
{
    return (this->m_fixed == other.m_fixed);
}

bool Fixed::operator!=( const Fixed& other ) const
{
    return (this->m_fixed != other.m_fixed);
}

// ------------------- Arithmetic operations

Fixed Fixed::operator+( const Fixed& other ) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-( const Fixed& other ) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*( const Fixed& other ) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/( const Fixed& other ) const
{
    return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++( void )
{
    ++this->m_fixed;
    return (*this);
}

Fixed Fixed::operator++( int )
{
    Fixed temp;

    temp = *this;
    this->m_fixed++;
    return (temp);
}

Fixed& Fixed::operator--( void )
{
    --this->m_fixed;
    return (*this);
}

Fixed Fixed::operator--( int )
{
    Fixed temp;

    temp = *this;
    this->m_fixed--;
    return (temp);
}

// ---------------------- getters and setters
int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->m_fixed);
}

void Fixed::setRawBits( const int newFixed )
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->m_fixed = newFixed;
}

// -------------------- Convert functions
float Fixed::toFloat( void ) const
{
    return ((float)this->m_fixed / (1 << Fixed::m_frac));
}

int Fixed::toInt( void ) const
{
    return (this->m_fixed >> Fixed::m_frac);
}

// ------------------- Static member functions declaration
Fixed& Fixed::min( Fixed& obj1, Fixed& obj2 )
{
    return (obj1 < obj2 ? obj1 : obj2);
}

const Fixed& Fixed::min( const Fixed& obj1, const Fixed& obj2 )
{
    return (obj1 < obj2 ? obj1 : obj2);
}

Fixed& Fixed::max( Fixed& obj1, Fixed& obj2 )
{
    return (obj1 > obj2 ? obj1 : obj2);
}

const Fixed& Fixed::max( const Fixed& obj1, const Fixed& obj2 )
{
    return (obj1 > obj2 ? obj1 : obj2);
}
