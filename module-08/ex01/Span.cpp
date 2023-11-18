#include "Span.hpp"

Span::Span( unsigned int N )
{
    this->__limit = N;
}

Span::Span( const Span& copy )
{
    if (this == &copy)
        return ;
    
    (*this) = copy;
}

Span::~Span()
{
    this->__list.clear();
    this->__limit = 0;
}

Span& Span::operator=( const Span& rhs )
{
    if (this == &rhs)
        return (*this);
    
    this->__list = rhs.__list;
    this->__limit = rhs.__limit;

    return (*this);
}

void Span::addNumber( const int number )
{
    if (this->__list.size() == this->__limit)
        throw std::runtime_error("Span is already full.");
    
    __list.push_back(number);
}

void Span::fill( unsigned int fillSize )
{
    if (!fillSize)
        return ;

    if ((fillSize + this->__list.size()) > this->__limit)
        throw std::runtime_error("Span don't have enough capacity.");

    while (fillSize--)
        this->addNumber( fillSize );
}

int Span::shortestSpan( void ) const
{
    if (this->__list.size() <= 1)
        throw std::runtime_error("Your span is very short to search shortest span!");

    return (*(std::min_element(this->__list.begin(), this->__list.end())));
}

int Span::longestSpan( void ) const
{
    if (this->__list.size() <= 1)
        throw std::runtime_error("Your span is very short to search longest span!");

    return (*(std::max_element(__list.begin(), __list.end())));
}