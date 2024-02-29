#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define UNDER "\033[4m"

class Span 
{
	private :
		std::vector<int> _span;
		int	_len;
		unsigned int _sizeAdded;
		Span();
	public :
		Span(unsigned int n);
		Span(const Span &copie);
		~Span();
		Span &operator=(const Span &copie);

		void	addNumbersRange(unsigned int len);
		void	addNumber(int N);
		void	showSpan();

		int		shortestSpan();
		int		longestSpan();

		std::vector<int>::iterator getBegin(){return (_span.begin());}
		std::vector<int>::iterator getEnd(){return (--_span.end());}

		class isFull : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class isEmpty : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class onlyOne : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class inputError : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

#endif