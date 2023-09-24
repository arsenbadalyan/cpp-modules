#include <iostream>
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    Ice * ice = new Ice();
    src->learnMateria(ice);
    src->learnMateria(new Cure());
    src->learnMateria(ice);
    src->learnMateria(ice);
    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(2);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return (0);
}