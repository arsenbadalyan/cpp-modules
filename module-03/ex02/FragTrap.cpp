#include "FragTrap.hpp"

// ------------------
// ctros, dtor
FragTrap::FragTrap( void )
{
    std::cout << "FragTrap Default ctor called!" << std::endl;
    FragTrap("unnamed");
}

FragTrap::FragTrap( std::string name ) : ClapTrap::ClapTrap(name)
{
    std::cout << "FragTrap Argument ctor called!" << std::endl;
    this->setHealth(100);
    this->setEnergy(50);
    this->setDemage(20);
}

FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap::ClapTrap(copy)
{
    std::cout << "FragTrap Copy ctor called!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap dtor called!" << std::endl;
}

// ------------------
// overloaded operators
FragTrap& FragTrap::operator=( const FragTrap& copy )
{
    ClapTrap::operator=(copy);

    return (*this);
}

// ------------------
// member functions
void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << this->getName() << " high fives." << std::endl;
}