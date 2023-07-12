#ifndef __WEAPON__H__
#define __WEAPON__H__

#include <iostream>

class Weapon {

public:

	Weapon(void);
	Weapon(std::string);
	~Weapon();

	std::string getType(void) const;
	void setType(std::string);

private:

	std::string m_type;

};

#endif  //!__WEAPON__H__