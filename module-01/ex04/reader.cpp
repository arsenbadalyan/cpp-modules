#include "reader.hpp"

void read_controller(char *fName, char *find, char *replace) {
	std::string filename(fName);
	std::string findStr(find);
	std::string replaceStr(replace);
	std::ifstream inputFile(filename);
	
	if (!(inputFile.is_open()))
		catch_exception(E_WRFLE);
	
	std::ofstream outputFile(filename.append(".replace"));

	if (outputFile.is_open())
		read_file(inputFile, outputFile, findStr, replaceStr);
	else
		catch_exception(E_WRFLE);
}

void read_file(std::ifstream& inputFile, std::ofstream& outputFile,
				std::string find, std::string replace) {
	std::string line;
	size_t pos;
	size_t length;

	length = find.length();
	while (std::getline(inputFile, line)) {
		pos = 0;
		while (1) {
			pos = line.find(find, pos);
			if (pos == std::string::npos)
				break ;
			line.erase(pos, length);
			line.insert(pos, replace);
			pos++;
		}
		outputFile << line << std::endl;
	}

}