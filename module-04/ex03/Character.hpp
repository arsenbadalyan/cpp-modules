#pragma once
#ifndef __CHARACTER__HPP__
#define __CHARACTER__HPP__

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {

    private:
        std::string _name;
        AMateria *_slots[4];
        AMateria **_floor_slots;

    public:
        Character( std::string const & );
        Character( const Character& );

        ~Character();

        Character& operator=( const Character& );

        std::string const & getName() const;
        void equip( AMateria* );
        void unequip( int );
        void use( int, ICharacter & );

        void save_materia( AMateria * );
};

#endif //!__ICHARACTER__HPP__