#pragma once
#ifndef __ICHARACTER__HPP__
#define __ICHARACTER__HPP__

#include <iostream>
#include <AMateria.hpp>

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip( AMateria* m ) = 0;
        virtual void unequip( int idx ) = 0;
        virtual void use( int idx, ICharacter& target ) = 0;
};

#endif //!__ICHARACTER__HPP__