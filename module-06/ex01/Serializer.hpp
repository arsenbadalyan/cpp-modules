#pragma once
#ifndef SERIALIZER__HPP__
#define SERIALIZER__HPP__

#include <iostream>
#include "Data.hpp"

class Serializer {

    public:
        static uintptr_t serialize( Data * ptr );
        static Data* deserialize( uintptr_t raw );

    public:
        ~Serializer() {}

    private:
        Serializer( void ) {}
        Serializer( const Serializer & ) {}

    private:
        void operator=( const Serializer & ) {}
};

#endif // !SERIALIZER__HPP__