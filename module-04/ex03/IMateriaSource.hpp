#pragma once
#ifndef __IMATERIASOURCE__HPP__
#define __IMATERIASOURCE__HPP__

#include <iostream>

#include "AMateria.hpp"

class AMateria;

class IMateriaSource {
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // !__IMATERIASOURCE__HPP__