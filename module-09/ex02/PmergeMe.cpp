#include "PmergeMe.hpp"

myDeque PmergeMe::unsorted_deque;
myVector PmergeMe::unsorted_vector;
myDeque PmergeMe::sorted_deque;
myVector PmergeMe::sorted_vector;

PmergeMe::PmergeMe( void ) {}
PmergeMe::PmergeMe( const PmergeMe & ) {}
PmergeMe::~PmergeMe() {}
void PmergeMe::operator=( const PmergeMe & ) {}

void PmergeMe::FJMI( char * userInput ) {
	if (!userInput)
		throw std::runtime_error(ERR_INVALID_ARGS);

	std::string listStr(userInput);

	PmergeMe::fill_arrays_by_user_input(userInput);

	PmergeMe::function_execution_time_calc_decorator(&PmergeMe::sort_deque);
	// PmergeMe::function_execution_time_calc_decorator(&PmergeMe::sort_list);
}

// sorting part
void PmergeMe::sort_deque( void ) {
	size_t straggler = 0;
	bool hasStraggler = false;

	if (PmergeMe::unsorted_deque.size() % 2) {
		straggler = *(PmergeMe::unsorted_deque.end());
		hasStraggler = true;
		PmergeMe::unsorted_deque.pop_back();
	}

	size_t listSize = PmergeMe::unsorted_deque.size() / 2;
	myDeque * pairs = PmergeMe::split_by_sorted_pairs(PmergeMe::unsorted_deque, listSize);

	PmergeMe::sort_pairs_by_larger(pairs, listSize);
	PmergeMe::merge_pairs(pairs, PmergeMe::sorted_deque, listSize, straggler, hasStraggler);

	size_t i = 0;
	while (i < listSize) {
		std::cout << pairs[i].begin().operator*() << " " << (--pairs[i].end()).operator*() << std::endl;
		i++;
	}
}

template <typename Container>
Container* PmergeMe::split_by_sorted_pairs( Container & container, size_t n ) {
	Container *pairs = new Container[n];
	size_t pairCounter = 0;

	while (!container.empty()) {
		typename Container::iterator a = container.begin();
		typename Container::iterator b = ++container.begin();

		pairs[pairCounter].push_back(*a);
		pairs[pairCounter].push_back(*b);

		if (*a > *b)
			std::iter_swap(pairs[pairCounter].begin(), --pairs[pairCounter].end());

		container.pop_front();
		container.pop_front();
		pairCounter++;
	}

	return (pairs);
}

template <typename Container>
void PmergeMe::sort_pairs_by_larger( Container * container, size_t n ) {
	if (n <= 1)
		return ;

	PmergeMe::sort_pairs_by_larger(container, n - 1);

	Container last = container[n - 1];
	int j = n - 2;

	while (j >= 0 && *(--container[j].end()) > *(--last.end())) {
		container[j + 1] = container[j];
		j--;
	}

	container[j + 1] = last;
}

template <typename Container>
void PmergeMe::merge_pairs( Container * pairs, Container & S, size_t n, size_t straggler, bool hasStraggler ) {
	Container pend;

	for (size_t i = 0; i < n; i++) {
		if (i == 0) {
			S.push_back(*(pairs[i].begin()));
		} else 
			pend.push_back(*(pairs[i].begin()));

		S.push_back(*(--pairs[i].end()));
	}

	typename Container::iterator pendIt = pend.begin();
	while (pendIt != pend.end()) {
		PmergeMe::binary_search_insertion(S, *pendIt);
		++pendIt;
	}

	pend.clear();

	if (hasStraggler)
		PmergeMe::binary_search_insertion(S, straggler);

}

template <typename Container>
void PmergeMe::binary_search_insertion( Container & S, size_t num ) {
	size_t startBound = 0, endBound = S.size();

	// while (1) {
	// 	size_t checker  = S.at(startBound + ((endBound - startBound) / 2));
	// 	if (checker > num)
	// 		endBound /= 2;
	// 	else if (checker < num)
	// 		startBound = endBound / 2;
	// 	else {
	// 		S.insert(S.begin() + checker, num);
	// 		break ;
	// 	}

	// 	// std::cout << num << " -> " << S.at(endBound - 1) << " - " << S.at(startBound) << std::endl;
	// 	std::cout << num << " -> " << endBound << " - " << startBound << std::endl;

	// 	if (endBound - startBound == 1) {
	// 		S.insert(S.begin() + startBound, num);
	// 		break ;
	// 	}

	// }
}

// helpers
void PmergeMe::fill_arrays_by_user_input( const std::string & userInput ) {
	size_t splittedInputSize;
	const std::string * splittedInput;
	size_t tempNum;

	splittedInput = PmergeMe::split(userInput, ' ', splittedInputSize);

	if (!splittedInputSize)
		throw std::runtime_error(ERR_INVALID_ARGS);

	for (size_t i = 0; i < splittedInputSize; i++) {
		if (!PmergeMe::is_valid_number(splittedInput[i]))
			throw std::runtime_error(ERR_NAN);

		tempNum = static_cast<size_t>(std::atoi((splittedInput[i]).c_str()));

		PmergeMe::unsorted_deque.push_back(tempNum);
		PmergeMe::unsorted_vector.push_back(tempNum);
	}
}

bool PmergeMe::is_valid_number( const std::string & source ) throw () {
	size_t i = 0;

	if (source[i] == '+')
		i++;
	
	while(source[i]) {
		if (!::isdigit(source[i]))
			return (false);
		i++;
	}

	return (true);
}

std::string* PmergeMe::split(const std::string& str, char delimiter, size_t & size) {
	size = 0;

	std::string token;
	std::stringstream ss(str);

	while (std::getline(ss, token, delimiter)) {
		if(!token.empty())
			size++;
	}

	std::string *dividedList = new std::string[size];
	size_t fillSize = 0;

	ss.clear();
	ss.seekg(0);

	while (std::getline(ss, token, delimiter)) {
		if(!token.empty()) {
			dividedList[fillSize] = token;
			fillSize++;
		}
	}

	return (dividedList);
}

void PmergeMe::function_execution_time_calc_decorator( void (*foo)(void) ) {
	timeval start, end;

	gettimeofday(&start, nullptr);
	foo();
	gettimeofday(&end, nullptr);

	std::cout << "Time to process a range of 3000 elements with std::[..] :" << std::endl;
}