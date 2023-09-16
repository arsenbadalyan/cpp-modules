#pragma once
#ifndef __AMATERIA__HPP__
#define __AMATERIA__HPP__

#include <iostream>

class AMateria {
    protected:
        const std::string _type;

    public:
        AMateria( std::string const & );

        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter&);
};

#endif // !__AMATERIA__HPP__