#ifndef SPAN_HPP
#define SPAN_HPP
#include <string>
#include <vector>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(Span& copy);
	~Span();

	Span& operator=(Span& rhs);

	void addNumber(int n);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	class FullSpanException : public std::exception {
		const char* what(void) const throw() {
			return "span is full";
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
	unsigned int m_stored;
};

#endif
