#ifndef ZOMBIE__HPP
#define ZOMBIE__HPP

#include <iostream>

class Zombie {

private:
	std::string _name;

public:

	Zombie(std::string);
	~Zombie();

	void announce(void);

};

#endif