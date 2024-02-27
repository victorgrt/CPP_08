#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define UNDER "\033[4m"

template<typename T>
typename T::iterator	easyfind(T container, int to_find)
{
	typename T::iterator found = std::find(container.begin(), container.end(), to_find);
	if (found != container.end())
	{
		std::cout << "Value " << BLUE << to_find << RESET << " found in container." << std::endl;
		return (found);
	}
	throw std::runtime_error(RED "Error : Couldn't find it" RESET);
}

#endif