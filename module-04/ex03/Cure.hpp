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

        AMateria* clone( void ) const;

        void use( ICharacter const & );
};

#endif //!__CURE__HPP__