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

unsigned int Span::shortestSpan( void ) const
{
    if (this->__list.size() <= 1)
        throw std::runtime_error("Your span is very short to search shortest span!");

    typedef std::list<int>::const_iterator ListCIt;
    
    unsigned int shortestDiff = UINT_MAX;
    unsigned int tempDiff = UINT_MAX;
    std::list<int> copyList = this->__list;
    
    copyList.sort();
    ListCIt startPos = copyList.begin();
    ListCIt nextPos = ++copyList.begin();

    while (nextPos != copyList.end())
    {
        tempDiff = std::abs(*startPos - *nextPos);
        if (tempDiff < shortestDiff)
            shortestDiff = tempDiff;

        startPos++;
        nextPos++;
    }

    return (shortestDiff);
}

unsigned int Span::longestSpan( void ) const
{
    if (this->__list.size() <= 1)
        throw std::runtime_error("Your span is very short to search longest span!");

    return (*(std::max_element(__list.begin(), __list.end())) - *(std::min_element(this->__list.begin(), this->__list.end())));
}