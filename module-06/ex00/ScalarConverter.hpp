#pragma once
#ifndef SCALAR_CONVERTER__HPP
#define SCALAR_CONVERTER__HPP

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cmath>

class ScalarConverter {

    public:
        static void convert( const std::string & );

    private:
        static void convert_char( const std::string & );
        static void convert_int( const std::string & );
        static void convert_float( const std::string & );
        static void convert_double( const std::string & );
        static void convert_inf_nan( const std::string &, int, size_t );
        static int check_input_type( const std::string &, size_t );
        static void print_char( char );
        static void print_int( int );
        static void print_float( float );
        static void print_double( double );

    private:
        enum { CHAR, INT, DOUBLE, FLOAT, INF, NANN };

    private:
        ScalarConverter( void );
        ~ScalarConverter();
        ScalarConverter( const ScalarConverter & );

    private:
        void operator=( const ScalarConverter & );
};

#endif // !SCALAR_CONVERTER__HPP