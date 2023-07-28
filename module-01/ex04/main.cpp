#include "reader.hpp"

int main( int ac, char** av )
{
	if (ac != 4)
		catch_exception(E_WRARG);

	av++;
	ac--;

	read_controller(av[0], av[1], av[2]);

	return (0);
}