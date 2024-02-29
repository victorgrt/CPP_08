#include "Span.hpp"

int	main(void)
{
	{	
		Span	test(5);
		test.addNumber(5);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		test.showSpan();
		test.shortestSpan();
		test.longestSpan();
	}
/*	{
		Span	high(10000);
		for (int i = 0; i < 10000; i++)
		{
			high.addNumber(i);
		}
		high.showSpan();
		try
		{
			high.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			high.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			high.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}*/
	srand(time(NULL));
	Span	myrand(50);
	myrand.showSpan();
	myrand.addNumbersRange(48);
	myrand.showSpan();
	myrand.addNumbersRange(1);
	myrand.showSpan();
	myrand.shortestSpan();
	myrand.longestSpan();
	std::cout << RED << "██████████████ ERROR MANAGEMENT ██████████████" << RESET << std::endl;
	Span empty(5);
	try
	{
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		empty.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		empty.addNumbersRange(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		empty.addNumbersRange(-10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span not_empty(5);
		for (int i = 0; i < 6; i++)
			not_empty.addNumber(i + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span only_one(1);
		only_one.addNumber(42);
		only_one.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span only_one(1);
		only_one.addNumber(42);
		only_one.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		myrand.addNumbersRange(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << RED << "██████████████████████████████████████████████" << RESET << std::endl;
	return (0);
}