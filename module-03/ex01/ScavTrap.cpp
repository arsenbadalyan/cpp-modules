#include "ScavTrap.hpp"

// ------------------
// ctros, dtor
ScavTrap::ScavTrap( void )
{
    std::cout << "ScavTrap Default ctor called!" << std::endl;
    ScavTrap("unnamed");
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap::ClapTrap(name)
{
    std::cout << "ScavTrap Argument ctor called!" << std::endl;
    this->setHealth(100);
    this->setEnergy(50);
    this->setDemage(20);
}

ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap::ClapTrap(copy)
{
    std::cout << "ScavTrap Copy ctor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap dtor called!" << std::endl;
}

// ------------------
// overloaded operators
ScavTrap& ScavTrap::operator=( const ScavTrap& copy )
{
    ClapTrap::operator=(copy);

    return (*this);
}

// ------------------
// overrided member functions
void ScavTrap::attack( const std::string& target )
{
    if ( this->_is_enough_energy() && this->_is_enough_health() )
    {
        std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getDemage() << " points of damage!" << std::endl;
        this->setEnergy(this->getEnergy() - 1);
    }
    return ;
}

// ------------------
// member functions
void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}