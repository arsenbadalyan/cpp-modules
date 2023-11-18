#pragma once
#ifndef SPAN_HPP__
#define SPAN_HPP__

#include <iostream>
#include <algorithm>
#include <list>

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
        int shortestSpan( void ) const;
        int longestSpan( void ) const;

    private:
        Span( void ) {}

    private:
        std::list<int> __list;
        unsigned int __limit;
};

#endif // !SPAN_HPP__