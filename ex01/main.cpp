#include "Span.hpp"

int	main(void)
{
	{	
		Span	test(5);
		try
		{
			test.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		test.addNumber(5);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		test.showSpan();
		test.shortestSpan();
		test.longestSpan();
		try
		{
			test.addNumber(4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// {
	// 	Span	high(10000);
	// 	for (int i = 0; i < 10000; i++)
	// 	{
	// 		high.addNumber(i);
	// 	}
	// 	high.showSpan();
	// 	try
	// 	{
	// 		high.addNumber(1);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	try
	// 	{
	// 		high.shortestSpan();
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	try
	// 	{
	// 		high.longestSpan();
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
	try
	{
		srand(time(NULL)); //on genere une seed en fonction du temps
		Span	myrand(50);
		myrand.showSpan();
		
		myrand.addNumbersRange2(50);
		myrand.showSpan();

		myrand.shortestSpan();
		myrand.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}