#pragma once
#ifndef __CAT__HPP__
#define __CAT__HPP__

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

    public:
        Cat( void );
        Cat( const Cat& );

        virtual ~Cat();

        Cat& operator=( const Cat& );

        void makeSound( void ) const;

};

#endif // !__CAT__HPP__