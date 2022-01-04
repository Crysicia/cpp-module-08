#include "span.hpp"

Span::Span() : m_array(NULL), m_capacity(0), m_stored(0) {}
Span::Span(unsigned int n) : m_array(new int[n]), m_capacity(n), m_stored(0) {}
Span::Span(Span& copy) { *this = copy; }
Span::~Span() {
	delete[] m_array;
}

Span& Span::operator=(Span& rhs) {
	if (this == &rhs) { return *this; }

	if (m_array) { delete[] m_array; }
	m_capacity = rhs.m_capacity;
	m_stored = rhs.m_stored;
	m_array = new int[m_capacity];

	for (unsigned int i = 0; i < m_stored; i++) {
		m_array[i] = rhs.m_array[i];
	}
	return *this;
}

void Span::addNumber(int n) {
	if (m_capacity == m_stored) { throw FullSpanException(); }

	m_array[m_stored] = n;
	m_stored++;
}
