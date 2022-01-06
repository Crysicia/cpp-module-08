#ifndef SPAN_HPP
#define SPAN_HPP
#include <string>
#include <vector>
#include <algorithm>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(Span& copy);
	virtual ~Span();

	Span& operator=(Span& rhs);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	class CannotAddNumberException : public std::exception {
		const char* what(void) const throw() {
			return "cannot add number(s)";
		}
	};

	class CannotFindSpanException : public std::exception {
		const char* what(void) const throw() {
			return "cannot find span";
		}
	};

private:
	std::vector<int> m_array;
	unsigned int m_capacity;
};

#endif
