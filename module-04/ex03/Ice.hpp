#pragma once
#ifndef __ICE__HPP__
#define __ICE__HPP__

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice( void );
        Ice( const Ice& );

        ~Ice();

        Ice& operator=( const Ice& );

};

#endif //!__ICE__HPP__