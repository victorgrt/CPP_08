#include "MutantStack.hpp"
#include <list>
#include <vector>

int	main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\nMain from subject with vector" << std::endl;
		std::vector<int>mvec;
		mvec.push_back(5);
		mvec.push_back(17);
		std::cout << *--mvec.end() << std::endl;
		mvec.erase(--mvec.end());
		std::cout << static_cast<int>(mvec.size()) << std::endl;
		mvec.push_back(3);
		mvec.push_back(5);
		mvec.push_back(737);
		mvec.push_back(0);
		std::vector<int>::iterator it = mvec.begin();
		std::vector<int>::iterator ite = mvec.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::vector<int> s(mvec);
	}
	{
		std::cout << "██████████████ TEST DES ITERATORS ██████████████" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout << "Begin : " << *mstack.begin() << std::endl;
		std::cout << "End : " << *--mstack.end() << std::endl;
		std::cout << "CBegin : " << *mstack.cbegin() << std::endl;
		std::cout << "CEnd : " << *--mstack.cend() << std::endl;
		std::cout << "RBegin : " << *mstack.rbegin() << std::endl;
		std::cout << "REnd : " << *--mstack.rend() << std::endl;


		std::cout << "\nVecteurs : " << std::endl;
		std::vector<int>mvec;
		mvec.push_back(5);
		mvec.push_back(17);
		mvec.erase(--mvec.end());
		mvec.push_back(3);
		mvec.push_back(5);
		mvec.push_back(737);
		mvec.push_back(0);
		std::vector<int>::iterator it2 = mvec.begin();
		std::vector<int>::iterator ite2 = mvec.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::cout << "Begin : " << *mvec.begin() << std::endl;
		std::cout << "End : " << *--mvec.end() << std::endl;
		// std::cout << "CBegin : " << *mvec.cbegin() << std::endl;
		// std::cout << "CEnd : " << *--mvec.cend() << std::endl;
		std::cout << "RBegin : " << *mvec.rbegin() << std::endl;
		std::cout << "REnd : " << *--mvec.rend() << std::endl;


		std::cout << "\nListe : " << std::endl;
		std::list<int>mlist;
		mlist.push_back(5);
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::vector<int>::iterator it3 = mvec.begin();
		std::vector<int>::iterator ite3 = mvec.end();
		++it3;
		--it3;
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
		std::cout << "Begin : " << *mlist.begin() << std::endl;
		std::cout << "End : " << *--mlist.end() << std::endl;
		// std::cout << "CBegin : " << *mlist.cbegin() << std::endl;
		// std::cout << "CEnd : " << *--mlist.cend() << std::endl;
		std::cout << "RBegin : " << *mlist.rbegin() << std::endl;
		std::cout << "REnd : " << *--mlist.rend() << std::endl;

	}
	
	return 0;
}