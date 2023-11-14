#pragma once
#ifndef ITER__HPP__
#define ITER__HPP__

#include <iostream>

template <typename T, typename U>
void iter( const T& array, size_t arrayLength,  const U& foo)
{
    for (size_t i = 0; i < arrayLength; i++)
        foo(array[i]);
}

#endif // !ITER__HPP__