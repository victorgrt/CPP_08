#include "Span.hpp"

Span::Span(unsigned int N)
{
	// this->_span = new int[N];
	_len = N;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &copie)
{
	if (this != &copie)
		this->_span = copie._span;
	return (*this);
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

void	Span::addNumber(int N)
{
	if (_span.size() == static_cast<size_t>(_len))
		throw isFull();
	_span.push_back(N);
}

std::vector<int> Span::getTab()
{
	return (this->_span);
}

void	Span::addNumbersRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_span.size() == static_cast<size_t>(_len))
		throw isFull();
	std::cout << "ici : " << *begin << " et " << *end << std::endl;
	while (begin != end)
	{
		_span.insert(end, rand());
		++begin;
	}
}

void	Span::addNumbersRange2(unsigned int len)
{
	(void) len;
	int begin = rand() / 10000000;
	_span.push_back(begin);
	int	end = rand() / 1000000;
	_span.push_back(end);
	unsigned int i = 0;
	while (_span.begin() != --_span.end())
	{
		if (i == len - 2)
			break;
		int random = rand() / 1000000;
		addNumber(random);
		++begin;
		++i;
	}
	// for (unsigned int i = 0; i < len - 1; i++)
	// {
	// 	int random = rand() / 10000;
	// 	_span.insert(_span.begin(), random);
	// }
	std::cout << *_span.begin() << " et " << *--_span.end() << std::endl;
}


int	Span::shortestSpan()
{
	if (_span.empty())
		throw isEmpty();
	else if (_span.size() == 1)
		throw onlyOne();
	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());
	int ret = tmp[1] - tmp[0];
	// std::cout << "Started at " << tmp[1] << "-" << tmp[0] << std::endl;
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (ret > (tmp[i + 1] - tmp[i]))
		{
			// std::cout << "Shortest : " << tmp[i + 1] << "-" << tmp[i] << std::endl;
			ret = tmp[i + 1] - tmp[i];
		}
	}
	return (ret);
}

int	Span::longestSpan()
{
	if (_span.empty())
		throw isEmpty();
	else if (_span.size() == 1)
		throw onlyOne();
	// std::cout << "Longest => " << *std::max_element(_span.begin(), _span.end()) << "-" << *std::min_element(_span.begin(), _span.end()) << std::endl;
	return (*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
}