#pragma once
#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>

class Fixed {

	public:
		Fixed( void );
		Fixed( Fixed& );
		Fixed& operator=( Fixed& );
		~Fixed();

		// member functions
		int getRawBits( void ) const;
		void setRawBits( const int );
	private:
		int m_fixed;
		static const int m_frac;
};

#endif