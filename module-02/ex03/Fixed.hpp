#pragma once
#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	
	public:
		// Constructors and destructor 
		Fixed( void );
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed& );
		~Fixed();

		// overloaded operators
		Fixed& operator=( const Fixed& );
		bool operator<( const Fixed& ) const;
		bool operator>( const Fixed& ) const;
		bool operator<=( const Fixed& ) const;
		bool operator>=( const Fixed& ) const;
		bool operator==( const Fixed& ) const;
		bool operator!=( const Fixed& ) const;
		Fixed operator+( const Fixed& ) const;
		Fixed operator-( const Fixed& ) const;
		Fixed operator*( const Fixed& ) const;
		Fixed operator/( const Fixed& ) const;
		Fixed operator++( int );
		Fixed& operator++( void );
		Fixed operator--( int );
		Fixed& operator--( void );

		// member functions
		int getRawBits( void ) const;
		void setRawBits( const int );
		float toFloat( void ) const;
		int toInt( void ) const;

		// static member functions
		static Fixed& min( Fixed&, Fixed& );
		static const Fixed& min( const Fixed&, const Fixed& );
		static Fixed& max( Fixed&, Fixed& );
		static const Fixed& max( const Fixed&, const Fixed& );

	private:
		int m_fixed;
		static const int m_frac;
};

std::ostream& operator<<( std::ostream&, const Fixed& );

#endif