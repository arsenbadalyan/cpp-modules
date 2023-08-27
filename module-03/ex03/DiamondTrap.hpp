#pragma once
#ifndef __DIAMONDTRAP__HPP__
#define __DIAMONDTRAP__HPP__

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string m_name;
        using FragTrap::m_health;
        using ScavTrap::m_energy;
        using FragTrap::m_damage;

    public:

        DiamondTrap( void );
        DiamondTrap( std::string );
        DiamondTrap( const DiamondTrap& );

        ~DiamondTrap();

        DiamondTrap& operator=( const DiamondTrap& );

        using ScavTrap::attack;
        void whoAmI( void );
};

#endif