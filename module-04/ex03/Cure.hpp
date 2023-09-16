#pragma once
#ifndef __CURE__HPP__
#define __CURE__HPP__

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        Cure( void );
        Cure( const Cure& );

        ~Cure();

        Cure& operator=( const Cure& );

};

#endif //!__CURE__HPP__