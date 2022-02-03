#include <iostream>
#include <list>
#include <stack>
#include "mutantstack.hpp"

int main(void) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	mstack.pop();

	std::cout << mstack.size() << std::endl;

	std::cout << "======================" << std::endl;
	mstack.push(1);
	mstack.push(6);
	mstack.push(12);
	mstack.push(21);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> stack(mstack);

	std::cout << "======================" << std::endl;
	std::list<int> the_list;

	the_list.push_back(1);
	the_list.push_back(6);
	the_list.push_back(12);
	the_list.push_back(21);

	std::list<int>::iterator itl = the_list.begin();
	std::list<int>::iterator itle = the_list.end();

	++itl;
	--itl;
	while (itl != itle) {
		std::cout << *itl << std::endl;
		++itl;
	}

	return 0;
}
