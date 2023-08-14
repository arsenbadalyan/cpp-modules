#pragma once
#ifndef __CLAPTRAP__HPP
#define __CLAPTRAP__HPP

#include <iostream>

#ifndef SHOW_DEFAULT_MSG
#define SHOW_DEFAULT_MSG true
#endif
class ClapTrap {

    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        virtual ~ClapTrap();
        ClapTrap( const ClapTrap& );

        // overloaded operators
        ClapTrap& operator=( const ClapTrap& );

        // member methods
        void attack( const std::string& );
        void takeDamage( unsigned int );
        void beRepaired( unsigned int );

        void printData( void );

        // getters and setters
        std::string getName( void );
        void setName( std::string );

        unsigned int getHealth( void );
        void setHealth( unsigned int );

        unsigned int getEnergy( void );
        void setEnergy( unsigned int );

        unsigned int getDamage( void );
        void setDamage( unsigned int );

    protected:
        std::string m_name;
        unsigned int m_health;
        unsigned int m_energy;
        unsigned int m_damage;

        bool _is_enough_health( void );
        bool _is_enough_energy( void );

        void _subtractHealth( unsigned int );
};

#endif // !__CLAPTRAP__HPP