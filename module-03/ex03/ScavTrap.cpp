#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// ---------- ctors
ScavTrap::ScavTrap( void ) : ClapTrap::ClapTrap()
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "ScavTrap Default ctor called!" << std::endl;
    this->setHealth(100);
    this->setEnergy(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap::ClapTrap( name )
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "ScavTrap Arguments ctor called!" << std::endl;
    this->setHealth(100);
    this->setEnergy(50);
    this->setDamage(20);
}

ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap::ClapTrap( copy )
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "ScavTrap Copy ctor called!" << std::endl;
}

// ---------- dtor
ScavTrap::~ScavTrap()
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "ScavTrap dtor called!" << std::endl;
}

// ---------- overloaded operators
ScavTrap& ScavTrap::operator=( const ScavTrap& rhs )
{
    ClapTrap::operator=(rhs);

    if (SHOW_DEFAULT_MSG)
        std::cout << "ScavTrap assignment operator called!" << std::endl;
    return (*this);
}

// ---------- member functions
void ScavTrap::guardGate( void )
{
    if ( _is_enough_health() )
        std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
    return ;
}

// ---------- override functions
void ScavTrap::attack( const std::string& target )
{
    if ( _is_enough_energy() && _is_enough_health() )
    {
        std::cout << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage!" << std::endl;
        this->setEnergy(this->getEnergy() - 1);
    }
    return ;
}