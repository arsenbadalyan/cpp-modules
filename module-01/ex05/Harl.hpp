#ifndef __HARL__H__
#define __HARL__H__

#include <iostream>

class Harl {
	public:
		void complain(std::string);
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void notFound(void);
};

#endif  //!__HARL__H__