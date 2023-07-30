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
// getters and setters

// ---- name
std::string ClapTrap::getName( void )
{
    return (this->m_name);
}

void ClapTrap::setName( std::string name )
{
    this->m_name = name;
}

// ---- health
unsigned int ClapTrap::getHealth( void )
{
    return (this->m_health);
}

void ClapTrap::setHealth( unsigned int health )
{
    this->m_health = health;
}

// ---- demage
unsigned int ClapTrap::getDemage( void )
{
    return (this->m_demage);
}

void ClapTrap::setDemage( unsigned int demage )
{
    this->m_demage = demage;
}

// ---- energy
unsigned int ClapTrap::getEnergy( void )
{
    return (this->m_energy);
}

void ClapTrap::setEnergy( unsigned int energy )
{
    this->m_energy = energy;
}

// -----------------------
// public member functions
void ClapTrap::attack( const std::string& target )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getDemage() << " points of damage!" << std::endl;
        this->setEnergy(this->getEnergy() - 1);
    }
    return ;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << "Claptrap " << this->getName() << " take demaged of " << amount << " amount!" << std::endl;
        this->_subtractHealth(amount);
        this->setEnergy(this->getEnergy() - 1);
    }
    return ;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << "Claptrap " << this->getName() << " will repired of " << amount << " amount!" << std::endl;
        this->setHealth(this->getHealth() + amount);
        this->setEnergy(this->getEnergy() - 1);
    }
    return ;
}

void ClapTrap::printData( void )
{
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Health: " << this->getHealth() << std::endl;
    std::cout << "Energy: " << this->getEnergy() << std::endl;
    std::cout << "Demage: " << this->getDemage() << std::endl;
}

// ------------------------------
// private stuff

bool ClapTrap::_is_enough_energy( void )
{
    if ( this->getEnergy() == 0 )
    {
        std::cout << "ClapTrap " << this->getName() << " don't have enough energy!" << std::endl;
        return (false);
    }
    return (true);
}

bool ClapTrap::_is_enough_health( void )
{
    if ( this->getHealth() == 0 )
    {
        std::cout << "ClapTrap " << this->getName() << " don't have enough health!" << std::endl;
        return (false);
    }
    return (true);
}

void ClapTrap::_subtractHealth( unsigned int amount )
{
    if ( amount > this->getHealth() )
        this->setHealth(0);
    else
        this->setHealth(this->getHealth() - amount);
}
