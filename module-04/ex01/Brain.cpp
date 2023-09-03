#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << "Brain * CTOR * was called!" << std::endl;
}

Brain::Brain( const Brain& target ) {
    std::cout << "Brain * COPY CTOR * was called!" << std::endl;
    Brain::operator=(target);
}

Brain::~Brain() {
    std::cout << "Brain * DTOR * was called!" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    std::cout << "Brain * ASSIGNMENT OPERATOR * was called!" << std::endl;
    if (&rhs == this)
        return (*this);
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i];
    return (*this);
}