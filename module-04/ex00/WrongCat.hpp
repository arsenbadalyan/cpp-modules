#pragma once
#ifndef __WrongCat__HPP__
#define __WrongCat__HPP__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        WrongCat( void );
        WrongCat( const WrongCat& );

        virtual ~WrongCat();

        WrongCat& operator=( const WrongCat& );

        void makeSound( void ) const;

};

#endif // !__WrongCat__HPP__