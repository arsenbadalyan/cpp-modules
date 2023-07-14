#ifndef __HARL__H__
#define __HARL__H__

#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		void complain(std::string);
};

#endif  //!__HARL__H__