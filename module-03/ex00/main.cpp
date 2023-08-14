#include <iostream>
#include "ClapTrap.hpp"

int main( int, char** )
{
    ClapTrap robot_1("rob-bot");
    ClapTrap robot_2;

    robot_1.attack("tree");
    robot_1.attack("enemy");
    robot_1.attack("another enemy");
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.printData();

    robot_2 = robot_1;
    robot_2.printData();
    return 0;
}
