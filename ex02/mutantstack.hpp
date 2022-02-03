#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() {};
	MutantStack(MutantStack& copy) { *this = copy; };
	virtual ~MutantStack() {};

	MutantStack& operator=(MutantStack& rhs) { std::stack<T>::operator=(rhs); };
	iterator end(void) { return this->c.end(); };
	iterator begin(void) { return this->c.begin(); };

	const_iterator end(void) const { return this->c.end(); };
	const_iterator begin(void) const { return this->c.begin(); };
};

#endif
