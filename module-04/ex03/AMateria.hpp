#pragma once
#ifndef __AMATERIA__HPP__
#define __AMATERIA__HPP__

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
    protected:
        std::string _type;

    public:
        AMateria( void );
        AMateria( std::string const & );
        AMateria( AMateria const & );

        virtual ~AMateria();

        virtual AMateria& operator=( AMateria const & );

        std::string const & getType( void ) const; //Returns the materia type

        virtual AMateria* clone( void ) const = 0;
        virtual void use( ICharacter const & );
};

#endif // !__AMATERIA__HPP__