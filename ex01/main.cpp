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

		std::vector<int> tab = test.getTab();
		for (size_t i = 0; i < tab.size(); i++)
			std::cout << "test[" << i << "] : " << tab[i] << std::endl;

		std::cout << "shortest : " << test.shortestSpan() << std::endl;
		std::cout << "longuest : " << test.longestSpan() << std::endl;

		try
		{
			test.addNumber(4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// Span	high(10000);
	// for (int i = 0; i < 10000; i++)
	// {
	// 	high.addNumber(i + (i % 3));
	// }
	// std::vector<int> tab = high.getTab();
	// for (size_t i = 0; i < tab.size(); i++)
	// 	std::cout << "high[" << i << "] : " << tab[i] << std::endl;
	// try
	// {
	// 	high.addNumber(1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	std::cout << "shortest : " << high.shortestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	std::cout << "longest : " << high.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	try
	{
		srand(time(NULL)); //on genere une seed en fonction du temps
		Span	myrand(50);
		
		myrand.addNumbersRange2(50);

		// std::cout << *rand.getBegin() << " et " << *rand.getEnd() << std::endl;
		// std::cout << rand.getBegin() << std::endl;
		std::vector<int> tab2 = myrand.getTab();
		for (size_t i = 0; i < tab2.size(); i++)
		std::cout << "rand[" << i << "] : " << tab2[i] << std::endl;
		std::cout << myrand.shortestSpan() << std::endl;
		std::cout << myrand.longestSpan() << std::endl;

		// myrand.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}