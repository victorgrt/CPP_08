#include "Span.hpp"

Span::Span() : _len(0), _sizeAdded(0){}

Span::Span(unsigned int N) : _len(N), _sizeAdded(0){}

Span::Span(const Span &copie) : _span(copie._span), _len(copie._len), _sizeAdded(copie._sizeAdded){}

Span::~Span(){}

Span &Span::operator=(const Span &copie)
{
	if (this != &copie)
	{	
		_span = copie._span;
		_len = copie._len;
		_sizeAdded = copie._sizeAdded;
	}
	return (*this);
}

//Ajoute N au vecteur en dernière position. Throw isFull() si on a atteint la taille maximale. 
void	Span::addNumber(int N)
{
	if (static_cast<unsigned int>(_len) == _sizeAdded)
		throw isFull();
	_span.push_back(N);
	_sizeAdded++;
}

//Ajoute adding_nb nombres (aléatoires) à la span dans la limite de la taille maximale.
void	Span::addNumbersRange(unsigned int adding_nb)
{
	if (adding_nb >= 2147483647)
		throw inputError();
	else if (_sizeAdded + adding_nb >= static_cast<unsigned int>(_len))
		throw isFull();
	int begin = rand() / 10000000;
	_span.push_back(begin);
	_sizeAdded++;
	int	end = rand() / 1000000;
	_span.push_back(end);
	_sizeAdded++;
	while (_span.begin() != --_span.end())
	{
		if (_sizeAdded >= static_cast<unsigned int>(_len)) //-2 parce qu'on en a push 2 avant.
			break;
		int random = rand() / 1000000;
		addNumber(random);
		++begin;
	}
}

//Trie la _span avec ::sort (#include <algorythm>) et compare la différence des éléments 2 à 2 et renvoi la plus petite.
int	Span::shortestSpan()
{
	int small, smallest;
	if (_span.empty())
		throw isEmpty();
	else if (_span.size() == 1)
		throw onlyOne();
	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());
	int ret = tmp[1] - tmp[0];
	small = tmp[1];
	smallest = tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (ret > (tmp[i + 1] - tmp[i]))
		{
			small = tmp[i + 1];
			smallest = tmp[i];
			ret = tmp[i + 1] - tmp[i];
		}
	}
	std::cout << "{" << GREEN << " SHORTEST " << RESET << "} : " << ret << " (" << small << " - " << smallest << ")" << std::endl;
	return (ret);
}

//Renvoi la soustraction du max_element et du min_element (#<algorythm>).
int	Span::longestSpan()
{
	if (_span.empty())
		throw isEmpty();
	else if (_span.size() == 1)
		throw onlyOne();
	std::cout << "{ " << GREEN << "LONGEST" << RESET << "} : " << *std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()) << " (" << *std::max_element(_span.begin(), _span.end()) << " - " << *std::min_element(_span.begin(), _span.end()) << ")" << std::endl;
	return (*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
}

//Affiche le contenue de la _span.
void	Span::showSpan()
{
	if (_span.empty())
	{
		std::cout << BLUE << "_____________________________________________" << RESET << std::endl;
		std::cout << BLUE << UNDER << "██████████████ PRINTING VECTOR ██████████████" << RESET << std::endl;
		std::cout << "Vector container is " << RED << "empty" << RESET << " and has a size " << RED << _len << RESET << " allocated." << std::endl;
		std::cout << BLUE << "█████████████████████████████████████████████" << RESET << std::endl;
		return ;
	}
	std::cout << BLUE << "_____________________________________________" << RESET << std::endl;
	std::cout << BLUE << UNDER << "██████████████ PRINTING VECTOR ██████████████" << RESET << std::endl;
	std::cout << "Vector's " << GREEN << "size" RESET << " : " << GREEN << _len << RESET << std::endl;
	int i = 0;
	for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		std::cout << "vector[" << i << "] = " << *it << std::endl;
		i++;
	}
	std::cout << BLUE << "█████████████████████████████████████████████" << RESET << std::endl;
}

const char *Span::isFull::what() const throw()
{
	return (RED "Error thrown : Span is Full" RESET);
}

const char *Span::isEmpty::what() const throw()
{
	return (RED "Error thrown : Span is Empty" RESET);
}

const char *Span::onlyOne::what() const throw()
{
	return (RED "Error thrown : Span has only 1 int stocked" RESET);
}

const char *Span::inputError::what() const throw()
{
	return (RED "Error thrown : Span needs a positive (not too big) positive number." RESET);
}
