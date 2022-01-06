#include "span.hpp"

Span::Span() : m_capacity(0) {}
Span::Span(unsigned int n) : m_capacity(n) {}
Span::Span(Span& copy) { *this = copy; }
Span::~Span() {}

Span& Span::operator=(Span& rhs) {
	if (this == &rhs) { return *this; }

	m_capacity = rhs.m_capacity;
	m_array = rhs.m_array;
	return *this;
}

void Span::addNumber(int n) {
	if (m_array.size() == m_capacity) { throw CannotAddNumberException(); }
	m_array.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (m_array.size() + std::distance(begin, end) > m_capacity) { throw CannotAddNumberException(); }
	m_array.insert(m_array.end(), begin, end);
}

unsigned int Span::shortestSpan() {
	if (m_array.size() <= 1) { throw CannotFindSpanException(); }

	unsigned int shortest_span = UINT_MAX;
	for (std::vector<int>::iterator fit = m_array.begin(); fit != m_array.end(); fit++) {
		for (std::vector<int>::iterator sit = fit + 1; sit != m_array.end(); sit++) {
			unsigned int current_span = static_cast<unsigned int>(std::abs(*fit - *sit));
			if (current_span < shortest_span) { shortest_span = current_span; }
		}
	}
	return shortest_span;
}

unsigned int Span::longestSpan() {
	if (m_array.size() <= 1) { throw CannotFindSpanException(); }
	std::vector<int>::iterator max = std::max_element(m_array.begin(), m_array.end());
	std::vector<int>::iterator min = std::min_element(m_array.begin(), m_array.end());
	return *max - *min;
}
