#pragma once
#ifndef __SCAVTRAP__HPP__
#define __SCAVTRAP__HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    
    public:
        
        // ctor, dtor
        ScavTrap( void );
        ScavTrap( const ScavTrap& );
        ScavTrap( std::string );
        ~ScavTrap();

        // overloaded operators
        ScavTrap& operator=( const ScavTrap& );

        // overrided member functions
        void attack( const std::string& );

        // member functions
        void guardGate();
};

#endif // !__SCAVTRAP__HPP__