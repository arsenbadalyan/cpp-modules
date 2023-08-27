#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap::ClapTrap( "unknown_clap_name" ),
    ScavTrap::ScavTrap( "unknown_clap_name" ),
    FragTrap::FragTrap( "unknown_clap_name" ),
    m_name("unknown") {
        
        if (SHOW_DEFAULT_MSG)
            std::cout << "DiamondTrap Default ctor called!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap::ClapTrap( name + "_clap_name" ),
    ScavTrap::ScavTrap( name + "_clap_name" ),
    FragTrap::FragTrap( name + "_clap_name" ),
    m_name(name) {
        
        if (SHOW_DEFAULT_MSG)
            std::cout << "DiamondTrap parameter ctor called!" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& target ) : ClapTrap::ClapTrap( target ),
    ScavTrap::ScavTrap( target ),
    FragTrap::FragTrap( target ) {

        if (SHOW_DEFAULT_MSG)
            std::cout << "DiamondTrap copy ctor called!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    if (SHOW_DEFAULT_MSG)
            std::cout << "DiamondTrap dtor called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {

    if (SHOW_DEFAULT_MSG)
            std::cout << "DiamondTrap copy ctor called!" << std::endl;

    if (&rhs == this)
        return (*this);

    this->m_name = rhs.m_name;
    ClapTrap::operator=(rhs);
    ScavTrap::operator=(rhs);
    FragTrap::operator=(rhs);

    return (*this);
}

// --------- member functions
void DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << this->m_name << std::endl;
    std::cout << "Claptrap name is " << ClapTrap::m_name << std::endl;
}