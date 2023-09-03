#pragma once
#ifndef __WrongAnimal__HPP__
#define __WrongAnimal__HPP__

#include <iostream>

class WrongAnimal {

    public:
        WrongAnimal( void );
        WrongAnimal( const WrongAnimal& );

        virtual ~WrongAnimal();

        WrongAnimal& operator=( const WrongAnimal& );

        void makeSound( void ) const;

        std::string getType( void ) const;
        void setType( std::string );

    protected:
        std::string type;

};

#endif // !__WrongAnimal__HPP__