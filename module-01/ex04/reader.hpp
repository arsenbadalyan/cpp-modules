#ifndef __READER__H__
#define __READER__H__

#include <fstream>
#include <iostream>

// Error messages
# define E_WRARG "Please give three parameters: [filename string1 string2]"
# define E_WRFLE "Please check if files that you passed is valid and come back !!"

std::string fromCharToString(char *str);
void catch_exception(std::string MSG);

// Reader
void read_controller(char *fName, char *find, char *replace);
void read_file(std::ifstream& inputFile, std::ofstream& outputFile, std::string find, std::string replace) ;


#endif  //!__READER__H__