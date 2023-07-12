#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main( void ) {
	int zombiesSize = 5;
	Zombie *zombies = zombieHorde(zombiesSize, "John");

	std::cout << "Testing..." << std::endl;
	for (int i = 0; i < zombiesSize; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}