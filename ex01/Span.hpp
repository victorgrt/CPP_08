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
	public :
		Span(unsigned int n);
		~Span();
		Span &operator=(const Span &copie);

		std::vector<int> getTab();

		void	addNumber(int N); //si full throw exception
		int		shortestSpan(); //pour les deux throw excpetion si pas de span genre vide ou 1 nb
		int		longestSpan();
		

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



};

#endif