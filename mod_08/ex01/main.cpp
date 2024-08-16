#include "Span.hpp"
#include <ctime>
#include <cstdlib>

void test_big() {

	std::cout << "\n" << BG_BRIGHT_BLACK"1. My test with big size of span:"RESET << std::endl;
	int sp_size = 11010;
	std::srand(time(NULL));

	try {
		Span sp = Span(sp_size);

		for (int i = 0; i < sp_size; ++i) {
			int j = std::rand() % sp_size;
			sp.addNumber(j);
			//std::cout << j << " ";
		}

		std::cout << CYAN"Shortest span: "RESET << sp.shortestSpan() << std::endl;
		std::cout << BLUE"Longest span: "RESET << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}


void test_subject() {
	std::cout << "\n" << BG_BRIGHT_BLACK"2. Standard small test from the subject:"RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main() {

	test_big();

	test_subject();

	return (0);
}