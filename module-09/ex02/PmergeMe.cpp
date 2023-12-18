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

	if (container.size() % 2) {
		straggler = *(--container.end());
		container.pop_back();
	}

	size_t listSize = container.size() / 2;
	Container * pairs = PmergeMe::split_by_sorted_pairs(container, listSize);

	PmergeMe::sort_pairs_by_larger(pairs, listSize);
	container.clear();
	PmergeMe::merge_pairs(pairs, container, listSize, straggler);

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
void PmergeMe::merge_pairs( Container * pairs, Container & S, size_t n, size_t straggler ) {
	size_t maxPendSize = n - 1 + (straggler ? 1 : 0);
	Container *pend = new Container[maxPendSize];
	size_t pendIdx = 0, pendQueueIdx = 2;

	for (size_t i = 0; i < n; i++) {
		if (i == 0) {
			S.push_back(*(pairs[i].begin()));
		} else {
			pend[pendIdx].push_back(*(pairs[i].begin()));
			pend[pendIdx++].push_back(pendQueueIdx++);
		}

		S.push_back(*(--pairs[i].end()));
	}

	if (straggler) {
		pend[pendIdx].push_back(straggler);
		pend[pendIdx++].push_back(pendQueueIdx++);
	}

	PmergeMe::group_pairs(pend, maxPendSize);
	PmergeMe::binary_search_insertion(S, pend, maxPendSize);

	delete[] pend;
}

template <typename Container>
void PmergeMe::group_pairs( Container * pairs, size_t pairsSize ) {
	size_t powerOfTwo = 1;
	size_t startIdx = 0;
	size_t endIdx = 0;
	size_t groupSize = 0;

	while (endIdx != pairsSize) {
		startIdx = endIdx;
		groupSize = pow(2, powerOfTwo++) - groupSize;
		endIdx = startIdx + groupSize;
		if (endIdx > pairsSize)
			endIdx = pairsSize;

		PmergeMe::reverse(pairs, startIdx, endIdx - 1);
	}
}

template <typename Container>
void PmergeMe::reverse( Container * source, size_t start, size_t end ) {
	while (start < end) {
		std::swap(source[start], source[end]);
		++start;
		--end;
	}
}

template <typename Container>
void PmergeMe::binary_search_insertion( Container & S, Container * pend, size_t pendSize ) {
	typename Container::iterator it;
	size_t idx = 0;

	while (idx < pendSize) {
		it = std::lower_bound(S.begin(), S.begin() + idx + pend[idx][1], pend[idx][0]);
		S.insert(it, pend[idx][0]);
		idx++;
	}
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

	long long sourceNum = std::atol(source.c_str());
	if (sourceNum <= 0 || sourceNum > std::numeric_limits<int>::max())
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
	if (container.size() > 1)
		foo(container);
	gettimeofday(&end_time, NULL);

	long duration = (end_time.tv_sec - start_time.tv_sec) * 1000000L + (end_time.tv_usec - start_time.tv_usec);

	if (PmergeMe::printMode)
		PmergeMe::print_container(container, "After: ");

	std::cout << "Time to process a range of " << container.size() << " elements with " << containerName << ": " << duration << "us" << std::endl;
}