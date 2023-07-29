#include <iostream>
#include "ClapTrap.hpp"

int main( int, char** )
{
    ClapTrap player1;

    player1.attack("tree");
    player1.attack("tree");
    player1.attack("tree");
    player1.attack("tree");
    player1.attack("tree");
    player1.takeDamage(9);
    player1.takeDamage(1);
    player1.takeDamage(0);

    return (0);
}
