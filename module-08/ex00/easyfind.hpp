#pragma once
#ifndef EASY_FIND_HPP__
#define EASY_FIND_HPP__

#include <iostream>

template <typename T>
typename T::const_iterator easyFind(const T& container, int num) {
    typedef typename T::const_iterator cit;

    cit result = std::find(container.begin(), container.end(), num);

    if (result != container.end())
        return (result);
    
    throw std::runtime_error("Cannot find element.");
}

template <typename T>
typename T::iterator easyFind(T& container, int num) {
    typedef typename T::iterator it;

    it result = std::find(container.begin(), container.end(), num);

    if (result != container.end())
        return (result);
    
    throw std::runtime_error("Cannot find element.");
}

#endif // !EASY_FIND_HPP__