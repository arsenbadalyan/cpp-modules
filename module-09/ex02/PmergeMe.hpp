#pragma once
#ifndef PMERGE_ME__HPP
#define PMERGE_ME__HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/time.h>

#define ERR_INVALID_ARGS "Invalid arguments"
#define ERR_NAN "Argument list should contain only valid positive integer sequence"

typedef std::deque<size_t> myDeque;
typedef std::vector<size_t> myVector;

class PmergeMe {

	public:
		static void FJMI( char * userInput );

	private: // sorting
		static void sort_deque( void );
		static void sort_list( void );
		template <typename Container>
		static Container* split_by_sorted_pairs( Container & container, size_t n );
		template <typename Container>
		static void sort_pairs_by_larger( Container * container, size_t n );
		template <typename Container>
		static void merge_pairs( Container * pairs, Container & S, size_t n, size_t straggler, bool hasStraggler );
		template <typename Container>
		static void binary_search_insertion( Container & S, size_t num );

	private: // helpers
		static void fill_arrays_by_user_input( const std::string & userInput );
		static bool is_valid_number( const std::string & source ) throw ();
		static std::string* split( const std::string& str, char delimiter, size_t& size );
		static void function_execution_time_calc_decorator( void (*foo)(void) );

	private:
		static myDeque unsorted_deque;
		static myVector unsorted_vector;
		static myDeque sorted_deque;
		static myVector sorted_vector;

	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe();

	private:
		void operator=( const PmergeMe & );
};

#endif // !PMERGE_ME__HPP