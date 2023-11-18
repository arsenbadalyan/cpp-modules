#pragma once
#ifndef MUTANT_STACK__HPP__
#define MUTANT_STACK__HPP__

#include <iostream>
#include <iterator>
#include <stack>

template <class _Tp, class _Container = std::deque<_Tp> >
class MutantStack : public std::stack<_Tp, _Container>
{
    public:
        MutantStack( void ) {}
        MutantStack( const MutantStack<_Tp, _Container>& copy ) : std::stack<_Tp, _Container>(copy) {}
        ~MutantStack() {}
    public:
        MutantStack<_Tp, _Container>& operator=( const MutantStack<_Tp, _Container>& rhs ) { std::stack<_Tp, _Container>::operator=(rhs); return ((*this)); }
    
    public:
        typedef typename std::stack<_Tp, _Container>::container_type::iterator iterator;
        typedef typename std::stack<_Tp, _Container>::container_type::const_iterator const_iterator;
        typedef typename std::stack<_Tp, _Container>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<_Tp, _Container>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin( void ) { return (this->c.begin()); }
        iterator end( void ) { return (this->c.end()); }

        const_iterator cbegin( void ) const { return (this->c.begin()); }
        const_iterator cend( void ) const { return (this->c.end()); }

        reverse_iterator rbegin( void ) { return (this->c.rbegin()); }
        reverse_iterator rend( void ) { return (this->c.rend()); }

        const_reverse_iterator crbegin( void ) const { return (this->c.rbegin()); }
        const_reverse_iterator crend( void ) const { return (this->c.rend()); }
};

#endif // !MUTANT_STACK__HPP__