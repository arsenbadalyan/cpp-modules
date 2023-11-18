#pragma once
#ifndef SPAN_HPP__
#define SPAN_HPP__

#include <iostream>
#include <algorithm>
#include <list>
#include <set>

class Span {

    public:
        Span( unsigned int N );
        Span( const Span& copy );
        ~Span();

    public:
        Span& operator=( const Span& rhs );

    public:
        void addNumber( const int number );
        void fill( unsigned int fillSize );
        unsigned int shortestSpan( void ) const;
        unsigned int longestSpan( void ) const;

    private:
        Span( void ) {}

    private:
        std::list<int> __list;
        unsigned int __limit;
};

#endif // !SPAN_HPP__