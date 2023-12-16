#pragma once
#ifndef BTC_HPP__
#define BTC_HPP__

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>

#define ERR_WRONG_ARG "Argument list must contain only input file!"
#define ERR_INVALID_INPUT_FILE "Input file is invalid please make sure that file exist or you have enough permissions"
#define ERR_UNAVAILABLE_DB "DB is unavailable"
#define ERR_INVALID_DB "Invalid DB"
#define ERR_INVALID_INPUT "Invalid input file"
#define ERR_EMPTY_DB "DB is empty"
#define ERR_INVALID "invalid"

#define ERR_BAD_INPUT "bad input => "
#define ERR_NEG_NUM "not a positive number."
#define ERR_LARGE_NUM "too large a number."
#define ERR_OUT_OF_BOUNDS_DATE "date is out of bounds"

typedef std::map<std::string, double> db_map;

class BitcoinExchange {

    public:
        static const std::string DB_NAME;
        static const std::string DB_DATE_COL_NAME;
        static const std::string DB_EXCHANGE_COL_NAME;
        static const std::string INPUT_FIRST_COL_NAME;
        static const std::string INPUT_SECOND_COL_NAME;
        static const int MAX_BOUND = 1000;
        static const int MIN_BOUND = 0;
        static const int MONTH_MAX_DAY[12];
    
    public:
        static db_map DB_COURSES_MAP;

    public:
        static void validateDB( void );
        static void executeInput( char * inputFile );

    private:
        static void calculateCourse( const std::string & date, const std::string & course );
        static bool isOnlyDigit( const std::string & str, bool checkDot );
        static bool isValidDate( const std::string & date );
        static bool isValidAndInBoundsNumber( const std::string & source, bool isDBCol );
        static bool isLeapYear( int year );
        static std::string* split(const std::string& str, char delimiter, size_t & size);
        static std::string trimWhitespaces( std::string & str );

    private:
        BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange & );
        ~BitcoinExchange();

    private:
        void operator=( const BitcoinExchange & );

};

#endif // !BTC_HPP__