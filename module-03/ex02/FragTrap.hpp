#pragma once
#ifndef __FRAGTRAP__HPP__
#define __FRAGTRAP__HPP__

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        // ctors
        FragTrap( void );
        FragTrap( const std::string& );
        FragTrap( const FragTrap& );

        // dtor
        ~FragTrap();

        // overloaded operators
        FragTrap& operator=( const FragTrap& );

        // member functions
        void highFivesGuys( void );
};

#endif // !__FRAGTRAP__HPP__