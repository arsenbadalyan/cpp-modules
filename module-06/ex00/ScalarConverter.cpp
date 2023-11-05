#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter( const ScalarConverter & ) { }
void ScalarConverter::operator=( const ScalarConverter & ) { }

void ScalarConverter::convert( const std::string & userInput ) {
    const size_t inputLength = userInput.length();
    const int inputType = ScalarConverter::check_input_type(userInput, inputLength);

    if (inputType == INF || inputType == NANN)
        ScalarConverter::convert_inf_nan(userInput, inputType, inputLength);
    else if (inputType == CHAR)
        ScalarConverter::convert_char(userInput);
    else if (inputType == INT)
        ScalarConverter::convert_int(userInput);
    else if (inputType == DOUBLE)
        ScalarConverter::convert_double(userInput);
    else
        ScalarConverter::convert_float(userInput);
}

int ScalarConverter::check_input_type( const std::string & userInput, size_t inputLength ) {
    if (userInput == "inf" || userInput == "+inf" || userInput == "-inf"
        || userInput == "inff" || userInput == "+inff" || userInput == "-inff")
        return (INF);

    if (userInput == "nan" || userInput == "nanf")
        return (NANN);

    if (inputLength == 1 && !std::isdigit(userInput[0]))
        return (ScalarConverter::CHAR);

    bool hasDot = userInput.find('.') != std::string::npos;
    bool hasF = userInput.find('f') != std::string::npos;

    if (inputLength <= 11 && !hasDot && !hasF) {
        long num = std::atol(userInput.c_str());
        if (num > INT_MIN && num < INT_MAX)
            return (ScalarConverter::INT);
    }

    if (!hasF)
        return (ScalarConverter::DOUBLE);

    return (ScalarConverter::FLOAT);
}

void ScalarConverter::convert_char( const std::string & userInput ) {
    char ch = userInput[0];

    ScalarConverter::print_char(static_cast<char>(ch));
    ScalarConverter::print_int(static_cast<int>(ch));
    ScalarConverter::print_float(static_cast<float>(ch));
    ScalarConverter::print_double(static_cast<double>(ch));
}

void ScalarConverter::convert_int( const std::string & userInput ) {
    int num = std::atoi(userInput.c_str());

    ScalarConverter::print_char(static_cast<char>(num));
    ScalarConverter::print_int(static_cast<int>(num));
    ScalarConverter::print_float(static_cast<float>(num));
    ScalarConverter::print_double(static_cast<double>(num));
}

void ScalarConverter::convert_double( const std::string & userInput ) {
    double num = std::strtod(userInput.c_str(), NULL);

    ScalarConverter::print_char(static_cast<char>(num));
    ScalarConverter::print_int(static_cast<int>(num));
    ScalarConverter::print_float(static_cast<float>(num));
    ScalarConverter::print_double(static_cast<double>(num));
}

void ScalarConverter::convert_float( const std::string & userInput ) {
    float num = std::atof(userInput.c_str());

    ScalarConverter::print_char(static_cast<char>(num));
    ScalarConverter::print_int(static_cast<int>(num));
    ScalarConverter::print_float(static_cast<float>(num));
    ScalarConverter::print_double(static_cast<double>(num));
}

void ScalarConverter::convert_inf_nan( const std::string & userInput, int type, size_t inputLength ) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (type == NANN) {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else {
        bool isFloat = userInput.find("ff") != std::string::npos;
        std::cout << "float: " << (isFloat ? userInput : (userInput + "f")) << std::endl;
        std::cout << "double: " << (isFloat ? userInput.substr(0, inputLength - 1) : userInput) << std::endl;
    }
}

void ScalarConverter::print_char( char ch ) {
    if (std::isprint(ch))
        std::cout << "char: '" << static_cast<char>(ch) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::print_int( int num ) {
    std::cout << "int: " << num << std::endl;
}

void ScalarConverter::print_double( double num ) {
    std::ostringstream str1;
    str1 << num;
    std::string userInput = str1.str();

    std::cout << "double: " << num << (!std::isinf(num) && userInput.find(".") == std::string::npos ? ".0" : "") << std::endl;
}

void ScalarConverter::print_float( float num ) {
    std::ostringstream str1;
    str1 << num;
    std::string userInput = str1.str();

    std::cout << "float: " << num << (!std::isinf(num) ? userInput.find(".") == std::string::npos ? ".0f" : "f" : "") << std::endl;
}