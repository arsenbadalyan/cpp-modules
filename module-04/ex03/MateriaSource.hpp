#pragma once
#ifndef __MATERIASOURCE__HPP__
#define __MATERIASOURCE__HPP__

#include <iostream>

#include "IMateriaSource.hpp"

class MateriaSource {

    public:

        MateriaSource( void );
        MateriaSource( MateriaSource const & );

        ~MateriaSource();

        MateriaSource & operator=( MateriaSource const & );

        void learnMateria( AMateria* );

        AMateria * createMateria( std::string const & );
};

#endif // !__MATERIASOURCE__HPP__