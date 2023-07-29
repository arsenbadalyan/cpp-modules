#include "ClapTrap.hpp"

// -------------- ctor, dtor
ClapTrap::ClapTrap( void )
{
    std::cout << "Default ctor called!" << std::endl;
    *this = ClapTrap("unnamed");
}

ClapTrap::ClapTrap( std::string name )
{
    std::cout << "Argument ctor called!" << std::endl;
    this->m_name = name;
    this->m_demage = 0;
    this->m_energy = 10;
    this->m_health = 10;
}

ClapTrap::~ClapTrap() {
    std::cout << "Dtor called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy )
{
    std::cout << "Copy ctor called!" << std::endl;
    *this = copy;
}

// ------------------------- overloaded operators
ClapTrap& ClapTrap::operator=( const ClapTrap& rhs )
{
    std::cout << "Equal operator called!" << std::endl;
    this->m_name = rhs.m_name;
    this->m_health = rhs.m_health;
    this->m_energy = rhs.m_energy;
    this->m_demage = rhs.m_demage;

    return (*this);
}

// -----------------------
// public member functions
void ClapTrap::attack( const std::string& target )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_demage << " points of damage!" << std::endl;
        this->m_energy--;
    }
    return ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << "Claptrap " << this->m_name << " take demaged of " << amount << " amount!" << std::endl;
        this->_subtractHealth(amount);
        this->m_energy--;
    }
    return ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << "Claptrap " << this->m_name << " will repired of " << amount << " amount!" << std::endl;
        this->m_health += amount;
        this->m_energy--;
    }
    return ;
}

// ------------------------------
// private stuff

bool ClapTrap::_is_enough_energy( void )
{
    if ( this->m_energy == 0 )
    {
        std::cout << "ClapTrap " << this->m_name << " don't have enough energy!" << std::endl;
        return (false);
    }
    return (true);
}

bool ClapTrap::_is_enough_health( void )
{
    if ( this->m_health == 0 )
    {
        std::cout << "ClapTrap " << this->m_name << " don't have enough health!" << std::endl;
        return (false);
    }
    return (true);
}

void ClapTrap::_subtractHealth( unsigned int amount )
{
    if ( amount > this->m_health )
        this->m_health = 0;
    else
        this->m_health -= amount;
}