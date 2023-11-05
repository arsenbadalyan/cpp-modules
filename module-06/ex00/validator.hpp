#pragma once
#ifndef __INPUT_VALIDATOR__
#define __INPUT_VALIDATOR__

#include <iostream>

bool hasNotAllowedChars( std::string userInput, size_t inputSize );
void validator( int argc, char ** userInputC );

#endif // !__INPUT_VALIDATOR__