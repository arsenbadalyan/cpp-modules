#include "FragTrap.hpp"

// ---------- ctors
FragTrap::FragTrap( void ) : ClapTrap::ClapTrap()
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "FragTrap Default ctor called!" << std::endl;
    this->setHealth(100);
    this->setEnergy(100);
    this->setDamage(30);
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap::ClapTrap( name )
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "FragTrap argument ctor called!" << std::endl;
    this->setHealth(100);
    this->setEnergy(100);
    this->setDamage(30);
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap::ClapTrap( other )
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "FragTrap copy ctor called!" << std::endl;
}

// ---------- dtor
FragTrap::~FragTrap()
{
    if (SHOW_DEFAULT_MSG)
        std::cout << "FragTrap dtor called!" << std::endl;
}

// ---------- assignment operator
FragTrap& FragTrap::operator=( const FragTrap& rhs )
{
    ClapTrap::operator=(rhs);

    if (SHOW_DEFAULT_MSG)
        std::cout << "FragTrap assignment operator called!" << std::endl;

    return (*this);
}

// ---------- member functions
void FragTrap::highFivesGuys( void )
{
    std::cout << this->getName() << " high fives to all !!" << std::endl;
}
