#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) {
	std::vector<int> vec;
	std::list<int> list;

	for (int i = 0; i < 20; i++) {
		vec.push_back(i);
		list.push_back(i);
	}

	try {
		easyfind(vec, 19);
		std::cout << "Number found !" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try {
		easyfind(vec, 1212);
		std::cout << "Number found !" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try {
		easyfind(vec, -1);
		std::cout << "Number found !" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try {
		easyfind(list, 19);
		std::cout << "Number found !" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try {
		easyfind(list, 1212);
		std::cout << "Number found !" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try {
		easyfind(list, -1);
		std::cout << "Number found !" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	return 0;
}
