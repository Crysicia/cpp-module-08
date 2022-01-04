#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <algorithm>

class ValueNotFoundException : public std::exception {
	const char* what(void) const throw() {
		return "value not found";
	}
};

template<typename T>
int easyfind(T& array, int to_find) {
	typename T::iterator it = std::find(array.begin(), array.end(), to_find);
	if (it == array.end()) { throw ValueNotFoundException(); }
	return (*it);
}

#endif
