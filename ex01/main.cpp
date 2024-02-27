#include "Span.hpp"

int	main(void)
{
	std::cout << "Coucou World" << std::endl;
	
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
	
	
	return (0);
}