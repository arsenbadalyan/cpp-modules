#pragma once
#ifndef __BRAIN__HPP__
#define __BRAIN__HPP__

#include <iostream>

class Brain {

    public:

        Brain( void );
        Brain( const Brain& );

        ~Brain();

        Brain& operator=( const Brain& );

        std::string ideas[100];

};

#endif //!__BRAIN__HPP__