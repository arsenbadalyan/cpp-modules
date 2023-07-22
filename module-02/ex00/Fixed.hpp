#pragma once
#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(Fixed&);
        Fixed& operator=(Fixed&);
        ~Fixed();

        // member functions
        int getRawBits(void) const;
        void setRawBits(const int);
    private:
        int fixed;
        static const int frac;
};

const int frac = 0;

#endif