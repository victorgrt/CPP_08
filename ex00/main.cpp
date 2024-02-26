#include "easyfind.hpp"
#include <list>

int	main(void)
{
	std::list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(3);
	mylist.push_back(42);
	mylist.push_back(66);
	mylist.push_back(42);

	std::cout << "Ma liste :" << std::endl;
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << *it << std::endl;
	try
	{
		std::list<int>::iterator res;
		res = easyfind(mylist,42);
		std::cout << *res << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator res2 = easyfind(mylist,666);
		if (res2 != mylist.end())
			std::cout << "Value found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}