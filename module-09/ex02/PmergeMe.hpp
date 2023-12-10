#pragma once
#ifndef PMERGE_ME__HPP
#define PMERGE_ME__HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <sys/time.h>

#define ERR_INVALID_ARGS "Invalid arguments"
#define ERR_NAN "Argument list should contain only valid positive integer sequence"

typedef std::deque<size_t> myDeque;
typedef std::vector<size_t> myVector;

class PmergeMe {

	public:
		static void FJMI( char ** userInput );

	private: // sorting
		template <typename Container>
		static void sort_container( Container & container );
		template <typename Container>
		static Container* split_by_sorted_pairs( Container & container, size_t n );
		template <typename Container>
		static void sort_pairs_by_larger( Container * container, size_t n );
		template <typename Container>
		static void merge_pairs( Container * pairs, Container & S, size_t n, size_t straggler, bool hasStraggler );
		template <typename Container>
		static void binary_search_insertion( Container & S, size_t num );

	private: // helpers
		static void fill_arrays_by_user_input( char ** userInput );
		static bool is_valid_number( const std::string & source ) throw ();
		template <typename Container>
		static void print_container( Container & container, const std::string & addnText );
		template <typename Container>
		static void container_print_execution_time_calc_decorator( void (*foo)(Container &), Container & container, const std::string & containerName );

	private:
		static myDeque temp_deque;
		static myVector temp_vector;
		static bool printMode;

	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe();

	private:
		void operator=( const PmergeMe & );
};

#endif // !PMERGE_ME__HPP