#pragma once
#ifndef __DOG__HPP__
#define __DOG__HPP__

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog( void );
        Dog( const Dog& );

        virtual ~Dog();

        Dog& operator=( const Dog& );

        void makeSound( void ) const;

};

#endif // !__DOG__HPP__