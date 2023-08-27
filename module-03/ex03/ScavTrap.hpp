#pragma once
#ifndef __SCAVTRAP__HPP__
#define __SCAVTRAP__HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:

        // ctors
        ScavTrap( void );
        ScavTrap( const ScavTrap& );
        ScavTrap( const std::string& );

        // dtor
        virtual ~ScavTrap();

        // overloaded operators
        ScavTrap& operator=( const ScavTrap& );

        // override functions
        void attack( const std::string& );

        // member function
        void guardGate( void );
};

#endif // !__SCAV_TRAP__HPP__