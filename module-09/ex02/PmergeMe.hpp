#pragma once
#ifndef PMERGE_ME__HPP
#define PMERGE_ME__HPP

#include <iostream>

class PmergeMe {

	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe();

	private:
		void operator=( const PmergeMe & );
};

#endif // !PMERGE_ME__HPP