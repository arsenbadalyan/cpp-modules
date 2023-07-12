#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void ) {
	Zombie *heapZombie = newZombie("John");

	randomChump("John from stack");
	heapZombie->announce();

	delete heapZombie;
	return (0);
}