#pragma once
#ifndef __ANIMAL__HPP__
#define __ANIMAL__HPP__

#include <iostream>

class Animal {

    public:
        Animal( void );
        Animal( const Animal& );

        virtual ~Animal();

        Animal& operator=( const Animal& );

        virtual void makeSound( void ) const = 0;

        std::string getType( void ) const;
        void setType( std::string );

    protected:
        std::string type;

};

#endif // !__ANIMAL__HPP__