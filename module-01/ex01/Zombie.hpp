#ifndef __ZOMBIE__H__
#define __ZOMBIE__H__

#include <iostream>

class Zombie {

private:
	std::string _name;

public:

	Zombie(void){};
	Zombie(std::string);
	~Zombie();

	void announce(void);

	// Setters
	void setName(std::string);

};

#endif  //!__ZOMBIE__H__