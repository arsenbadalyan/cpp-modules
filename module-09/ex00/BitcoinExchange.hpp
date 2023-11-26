#pragma once
#ifndef BTC_HPP__
#define BTC_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <algorithm>

#define ERR_UNAVAILABLE_DB "DB is unavailable"
#define ERR_INVALID_DB "Invalid DB"
#define ERR_EMPTY_DB "DB is empty"
#define ERR_INVALID "invalid"

typedef std::vector<std::string> string_vector;
typedef std::map<std::string, double> db_map;

class BitcoinExchange {

    public:
        static const std::string DB_NAME;
        static const std::string DB_DATE_COL_NAME;
        static const std::string DB_EXCHANGE_COL_NAME;
        static const int MAX_BOUND = 1000;
        static const int MIN_BOUND = 0;
        static const int MONTH_MAX_DAY[12];
    
    public:
        static db_map DB_COURSES_MAP;

    public:
        static void validateDB( void );
        // static void validateInput( char * fileName );
        static bool isValidDate( const std::string & date );
        static bool isValidAndInBoundsNumber( const std::string & source, bool isDBCol );

    private:
        static bool isOnlyDigit( const std::string & str, bool checkDot );
        static bool isLeapYear( int year );
        static string_vector split(const std::string& str, char delimiter);

    private:
        BitcoinExchange( void ) {}
        BitcoinExchange( const BitcoinExchange & ) {}
        ~BitcoinExchange() {}

    private:
        void operator=( const BitcoinExchange & ) {}

};

#endif // !BTC_HPP__