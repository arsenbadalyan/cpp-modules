#pragma once
#ifndef RPN__HPP__
#define RPN__HPP__

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

#define ERR_WRONG_ARG_LIST "Please give one argument with expression"
#define ERR_WRONG_EXPR "Expression is wrong please fix it"
#define ERR_ZERO_EXC "You cannot divide expression result to zero"

typedef double (*ExecuteOperation)(double, double);

class RPN {

    public:
        static void executeExpression( char * expression );

    private:
        static std::string* split( const std::string& str, char delimiter, size_t& size );
        static bool isValidExpressionItem( const std::string & exprItem );
        static const std::string ACCEPTED_NUMERIC_OPERATIONS;

    private:
        static double plus( double rvalue, double lvalue );
        static double minus( double rvalue, double lvalue );
        static double divide( double rvalue, double lvalue );
        static double multiply( double rvalue, double lvalue );


    private:
        RPN( void );
        RPN( const RPN& );
        ~RPN();

    private:
        void operator=( const RPN& );

};

#endif // !RPN__HPP__