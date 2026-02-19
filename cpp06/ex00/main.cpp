#include "ScalarConv.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "Need a value" << std::endl;
		return (0);
	}
	if (ac > 2)
	{
		std::cout << "Need a single value" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}
