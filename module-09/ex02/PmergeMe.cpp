#include "PmergeMe.hpp"

myDeque PmergeMe::temp_deque;
myVector PmergeMe::temp_vector;
bool PmergeMe::printMode;

PmergeMe::PmergeMe( void ) {}
PmergeMe::PmergeMe( const PmergeMe & ) {}
PmergeMe::~PmergeMe() {}
void PmergeMe::operator=( const PmergeMe & ) {}

void PmergeMe::FJMI( char ** userInput ) {
	if (!userInput)
		throw std::runtime_error(ERR_INVALID_ARGS);

	PmergeMe::printMode = true;
	PmergeMe::fill_arrays_by_user_input(userInput);

	PmergeMe::print_container(PmergeMe::temp_deque, "Before: ");
	PmergeMe::container_print_execution_time_calc_decorator(&PmergeMe::sort_container, PmergeMe::temp_deque, "std::deque");
	PmergeMe::printMode = false;
	PmergeMe::container_print_execution_time_calc_decorator(&PmergeMe::sort_container, PmergeMe::temp_vector, "std::vector");

	PmergeMe::temp_deque.clear();
	PmergeMe::temp_vector.clear();
}

// sorting part
template <typename Container>
void PmergeMe::sort_container( Container & container ) {
	size_t straggler = 0;
	bool hasStraggler = false;

	if (container.size() % 2) {
		straggler = *(--container.end());
		hasStraggler = true;
		container.pop_back();
	}

	size_t listSize = container.size() / 2;
	Container * pairs = PmergeMe::split_by_sorted_pairs(container, listSize);

	PmergeMe::sort_pairs_by_larger(pairs, listSize);
	container.clear();
	PmergeMe::merge_pairs(pairs, container, listSize, straggler, hasStraggler);

	delete[] pairs;
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

		container.erase(container.begin(), container.begin() + 2);
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
	typename Container::iterator it = std::lower_bound(S.begin(), S.end(), num);

	S.insert(it, num);
}

// helpers
void PmergeMe::fill_arrays_by_user_input( char ** userInput ) {
	size_t tempNum;

	for (size_t i = 0; userInput[i]; i++) {
		if (!PmergeMe::is_valid_number(userInput[i]))
			throw std::runtime_error(ERR_NAN);

		tempNum = static_cast<size_t>(std::atoi(userInput[i]));

		PmergeMe::temp_deque.push_back(tempNum);
		PmergeMe::temp_vector.push_back(tempNum);
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

	if (std::atol(source.c_str()) > std::numeric_limits<int>::max())
		return (false);

	return (true);
}

template <typename Container>
void PmergeMe::print_container( Container & container, const std::string & addnText ) {
	std::cout << addnText;

	typename Container::iterator it = container.begin();

	for (; it != container.end(); ++it) {
		std::cout << (*it) << " ";
	}

	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::container_print_execution_time_calc_decorator( void (*foo)(Container &), Container & container, const std::string & containerName ) {
	struct timeval start_time, end_time;

	gettimeofday(&start_time, NULL);
	foo(container);
	gettimeofday(&end_time, NULL);

	long duration = (end_time.tv_sec - start_time.tv_sec) * 1000000L + (end_time.tv_usec - start_time.tv_usec);

	if (PmergeMe::printMode)
		PmergeMe::print_container(container, "After: ");

	std::cout << "Time to process a range of " << container.size() << " elements with " << containerName << ": " << duration << "us" << std::endl;
}