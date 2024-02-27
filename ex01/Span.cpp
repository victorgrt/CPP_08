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

int	Span::shortestSpan()
{
	if (_span.empty())
		throw isEmpty();
	else if (_span.size() == 1)
		throw onlyOne();
	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());
	int ret = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		if (ret > (tmp[i + 1] - tmp[i]))
			ret = tmp[i + 1] - tmp[i];
	}
	return (ret);
}

int	Span::longestSpan()
{
	if (_span.empty())
		throw isEmpty();
	else if (_span.size() == 1)
		throw onlyOne();
	return (*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
}