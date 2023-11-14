#pragma once
#ifndef WHATEVER_HPP__
#define WHATEVER_HPP__

#include <iostream>

template<typename T>
void swap( T& a, T& b )
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}

template<typename T>
const T& min( const T& a, const T& b )
{
    return (a >= b ? b : a);
}

template<typename T>
const T& max( const T& a, const T& b )
{
    return (a <= b ? b : a);
}

#endif // !WHATEVER_HPP__