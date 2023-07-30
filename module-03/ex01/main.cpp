#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    // Сhecking all constructors
    ClapTrap Robot;
    ClapTrap Kiborg("Borderlands");
    ClapTrap Clon(Kiborg);
    Robot = Clon;

    std::cout<<std::endl;
    // Parameter check
    Robot.printData();
    Kiborg.printData();
    Clon.printData();

    std::cout<<std::endl;

    std::cout<<"\tRobot"<<std::endl;
    Robot.attack("Kiborg");
    Robot.takeDamage(8);
    Robot.printData();
    Robot.beRepaired(3);
    Robot.printData();

    std::cout<<std::endl;
    for(int i = 0; i <= 6; i++) Robot.attack("Clon");
    std::cout<<std::endl;

    Robot.printData();
    Robot.beRepaired(2);
    Robot.printData();
    Robot.attack("Kiborg");
    std::cout<<std::endl;

    std::cout<<"\tKiborg"<<std::endl;
    Kiborg.takeDamage(99);
    Kiborg.printData();

    std::cout<<std::endl;
    // Сall all destructors
    return 0;
}
