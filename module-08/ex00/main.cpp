#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>
#include "easyfind.hpp"

typedef std::list<int> IntList;
typedef std::vector<int> IntVector;

class ForTest {
    public:
        template <typename T, typename Func>
        void tryToExecute( T& container, const Func& foo, int search ) const
        {
            try {
                foo(container, search);
                std::cout << "Success: element - " << search << " has find." << std::endl;
            } catch (const std::exception &exc) {
                std::cout << "Error: " << exc.what() << std::endl;
            }
        }
};


int main( int, char ** )
{
    ForTest tester;

    std::cout << "VECTOR ---------------" << std::endl;
    IntVector vector;

    vector.push_back(5);
    vector.push_back(4);
    vector.push_back(77);
    vector.push_back(-3);

    typedef IntVector::iterator (* IntVectorFoo)(IntVector&, int);
    tester.tryToExecute<IntVector, IntVectorFoo>(vector, ::easyFind, 5);
    tester.tryToExecute<IntVector, IntVectorFoo>(vector, ::easyFind, 0);
    tester.tryToExecute<IntVector, IntVectorFoo>(vector, ::easyFind, -7);

    std::cout << "LIST ---------------" << std::endl;
    IntList list;

    list.push_front(776);
    list.push_back(345);
    list.push_back(678);
    list.push_back(42);
    list.push_back(543);

    typedef IntList::iterator (* IntListFoo)(IntList&, int);
    tester.tryToExecute<IntList, IntListFoo>(list, ::easyFind, 333);
    tester.tryToExecute<IntList, IntListFoo>(list, ::easyFind, 42);
    tester.tryToExecute<IntList, IntListFoo>(list, ::easyFind, -3456);

    return (0);
}