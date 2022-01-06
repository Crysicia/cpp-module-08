#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack();
	MutantStack(MutantStack& copy);
	virtual ~MutantStack();

	MutantStack& operator=(MutantStack& rhs);
	iterator end(void) { return this->c.end(); };
	iterator begin(void) { return this->c.begin(); };
};

#endif
