#pragma once
#ifndef __WrongDog__HPP__
#define __WrongDog__HPP__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {

    public:
        WrongDog( void );
        WrongDog( const WrongDog& );

        virtual ~WrongDog();

        WrongDog& operator=( const WrongDog& );

        void makeSound( void ) const;

};

#endif // !__WrongDog__HPP__