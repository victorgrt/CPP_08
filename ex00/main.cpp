#include "easyfind.hpp"
#include <list>
#include <vector>

int	main(void)
{
	std::cout << BLUE << "██████████████   [ LIST ]  ██████████████" << RESET << std::endl;
	{
		std::list<int> *mylist = new std::list<int>[5];
		mylist->push_back(1);
		mylist->push_back(3);
		mylist->push_back(42);
		mylist->push_back(66);
		mylist->push_back(42);

		std::cout << YELLOW << "██████████████	Ma liste : ██████████████" << RESET << std::endl;
		for (std::list<int>::iterator it = mylist->begin(); it != mylist->end(); it++)
			std::cout << *it << std::endl;
		std::cout << YELLOW << "██████████████	EASYFIND 42 ██████████████" << RESET << std::endl;
		try
		{
			std::list<int>::iterator res;
			res = easyfind(mylist,42);
			std::cout << GREEN << "res : " << *res << RESET << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << RED << "█████████████ EASYFIND 666 ██████████████" << RESET << std::endl;
		try
		{
			std::list<int>::iterator res2 = easyfind(mylist,666);
			if (res2 != mylist->end())
				std::cout << "Value found" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete[] mylist;
	}
	std::cout << BLUE << "██████████████ [VECTORS] ██████████████" << RESET << std::endl;
	{
		std::vector<int> *myvector = new std::vector<int>[5];
		myvector->push_back(3);
		myvector->push_back(42);
		myvector->push_back(5);
		myvector->push_back(9);
		myvector->push_back(669);

		std::cout << YELLOW << "██████████████	Vector : ██████████████" << RESET << std::endl;
		for (std::vector<int>::iterator it = myvector->begin(); it != myvector->end(); it++)
			std::cout << *it << std::endl;
		std::cout << YELLOW << "██████████████	EASYFIND 42 ██████████████" << RESET << std::endl;
		try
		{
			std::vector<int>::iterator res;
			res = easyfind(myvector,42);
			std::cout << GREEN << "res : " << *res << RESET << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << RED << "██████████████ EASYFIND 666 ██████████████" << RESET << std::endl;
		try
		{
			std::vector<int>::iterator res2 = easyfind(myvector,666);
			if (res2 != myvector->end())
				std::cout << "Value found" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete[] myvector;
	}

	return (0);
}