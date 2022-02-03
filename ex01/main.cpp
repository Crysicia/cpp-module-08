#include "span.hpp"
#include <iostream>

int main(void)
{
	std::vector<int> ints;

	for (int i = 0; i < 10000; i++) {
		ints.push_back(i);
	}
	std::random_shuffle(ints.begin(), ints.end());

	std::cout << "---- Initialize Spans ----" << std::endl;
	Span ten_k(10000);
	Span five(5);
	Span zero(0);

	std::cout << "---- Call addNumber on Spans ----" << std::endl;
	ten_k.addNumber(ints.begin(), ints.end());

	five.addNumber(17);
	five.addNumber(5);
	five.addNumber(3);
	five.addNumber(9);
	five.addNumber(11);

	std::cout << "---- Initialize span using copy ----" << std::endl;
	Span five_copy;
	Span ten_k_copy(ten_k);
	five_copy = five;

	std::cout << "---- Call shortestSpan on 10K ----" << std::endl;
	std::cout << ten_k.shortestSpan() << std::endl;
	std::cout << ten_k_copy.shortestSpan() << std::endl;

	std::cout << "---- Call shortestSpan on 5 ----" << std::endl;
	std::cout << five.shortestSpan() << std::endl;
	std::cout << five_copy.shortestSpan() << std::endl;

	std::cout << "---- Call shortestSpan on 0 ----" << std::endl;
	try { zero.shortestSpan(); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "---- Call longestSpan on 10K ----" << std::endl;
	std::cout << ten_k.longestSpan() << std::endl;
	std::cout << ten_k_copy.longestSpan() << std::endl;

	std::cout << "---- Call longestSpan on 5 ----" << std::endl;
	std::cout << five.longestSpan() << std::endl;
	std::cout << five_copy.longestSpan() << std::endl;

	std::cout << "---- Call longestSpan on 0 ----" << std::endl;
	try { zero.longestSpan(); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "---- Call addNumber on full span ----" << std::endl;
	try { five.addNumber(3); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { five_copy.addNumber(3); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { five.addNumber(ints.begin(), ints.begin() + 1); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { five_copy.addNumber(ints.begin(), ints.begin() + 1); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }


}
