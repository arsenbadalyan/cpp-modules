#pragma once
#ifndef __CLAPTRAP__HPP
#define __CLAPTRAP__HPP

#include <iostream>

class ClapTrap {

    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        ~ClapTrap();
        ClapTrap( const ClapTrap& );

        // overloaded operators
        ClapTrap& operator=( const ClapTrap& );

        // member methods
        void attack( const std::string& );
        void takeDamage( unsigned int );
        void beRepaired( unsigned int );

    private:
        std::string m_name;
        unsigned int m_health;
        unsigned int m_energy;
        unsigned int m_demage;

        bool _is_enough_health( void );
        bool _is_enough_energy( void );

        void _subtractHealth( unsigned int );
};

#endif // !__CLAPTRAP__HPP