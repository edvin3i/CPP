#include "easyfind.hpp"

void test_vector() {
	int int_arr[] = {1, 3, 5, 8, 6, 7};
	std::vector<int> v_int(int_arr , int_arr + 6);
	v_int.push_back(42);

	try {
		int val = *easyfind(v_int, 42);
		std::cout << BLUE"Number "MAGENTA << val << \
			BLUE" is found in the"GREEN" VECTOR "BLUE"container"RESET << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void test_deque() {
	int int_arr[] = {45, 2334, 42, 53, 16, 54};
	std::deque<int> q_int(int_arr , int_arr + 6);

	try {
		int val = *easyfind(q_int, 42);
		std::cout << BLUE"Number "MAGENTA << val << \
			BLUE" is found in the"CYAN" DQUEUE "BLUE"container"RESET << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void test_list() {
	int int_arr[] = {7, 2, 8, 3, 15, 42};
	std::list<int> l_int(int_arr , int_arr + 6);

	try {
		int val = *easyfind(l_int, 42);
		std::cout << BLUE"Number "MAGENTA << val << \
			BLUE" is found in the"YELLOW" LIST "BLUE"container"RESET << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

int main() {

	test_vector();

	test_deque();

	test_list();

	return (0);
}