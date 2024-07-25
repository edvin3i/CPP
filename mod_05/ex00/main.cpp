#include "includes/Bureaucrat.hpp"

void print_bureaucrat(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > 75) {
		std::cout << BRIGHT_YELLOW << bureaucrat << RESET << std::endl;
	}
	else {
		std::cout << GREEN << bureaucrat << RESET << std::endl;
	}
}

void test_bottom_edge(void) {
	Bureaucrat alice("Alice", 3);
	print_bureaucrat(alice);
	std::cout << BRIGHT_CYAN"First try to increment grade for "BRIGHT_BLUE \
					<< alice.getName() << RESET << std::endl;
	alice.incGrade();
	print_bureaucrat(alice);
	std::cout << BRIGHT_CYAN"Second try to increment grade for "BRIGHT_BLUE \
					<< alice.getName() << RESET << std::endl;
	alice.incGrade();
	print_bureaucrat(alice);
	std::cout << BRIGHT_CYAN"Third try to increment grade for "BRIGHT_BLUE \
					<< alice.getName() << RESET << std::endl;
	alice.incGrade();
	print_bureaucrat(alice);
}

void test_top_edge(void) {
	Bureaucrat bob("Bob", 148);
	print_bureaucrat(bob);
	std::cout << BRIGHT_CYAN"First try to decrement grade for "BRIGHT_BLUE \
					<< bob.getName() << RESET << std::endl;
	bob.decGrade();
	print_bureaucrat(bob);
	std::cout << BRIGHT_CYAN"Second try to decrement grade for "BRIGHT_BLUE \
					<< bob.getName() << RESET << std::endl;
	bob.decGrade();
	print_bureaucrat(bob);
	std::cout << BRIGHT_CYAN"Third try to decrement grade for "BRIGHT_BLUE \
					<< bob.getName() << RESET << std::endl;
	bob.decGrade();
	print_bureaucrat(bob);
}

void test_wrong_instance(std::string init_name, int init_grade) {
	Bureaucrat test_instance(init_name, init_grade);
}

void test_others(void) {
	Bureaucrat b1("Firsty", 10);
	Bureaucrat b2;
	Bureaucrat b3(b1);

	std::cout << "B1 address: " << &b1 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << "B2 address: " << &b2 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << "B3 address: " << &b3 << std::endl;
	std::cout << b3 << std::endl;

	std::cout << BG_BRIGHT_BLACK"Lets increase and decrease grades!"RESET << std::endl;
	b2.incGrade();
	std::cout << b2 << std::endl;
	b3.decGrade();
	std::cout << b3 << std::endl;

	std::cout << BG_BRIGHT_BLACK"Check final states"RESET << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
}

int main(void) {

	/* Check the edges	*/
	/* 1. Bottom edge		*/
	std::cout << "\n" << BG_BLUE"=============== 1. Bottom edge ==============="RESET << std::endl;
	try {
		test_bottom_edge();
	}
	catch (const std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 2. Top edge	*/
	std::cout << "\n" << BG_BLUE"=============== 2. Top edge ==============="RESET << std::endl;
	try {
		test_top_edge();
	}
	catch (const std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 3. Create the class instance with a wrong init value (LOW)	*/
	std::cout << "\n" << BG_BLUE"=============== 3. Wrong class instance (LOW) ==============="RESET << std::endl;
	try {
		test_wrong_instance("Wolfgang", 0);
	}
	catch (const std::exception &e) {
		std::cerr << "Wrong class instance does not created." << std::endl;
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 4. Create the class instance with a wrong init value (HIGH)	*/
	std::cout << "\n" << BG_BLUE"=============== 4. Wrong class instance (HIGH) ==============="RESET << std::endl;
	try {
		test_wrong_instance("Zaphod", 1000);
	}
	catch (const std::exception &e) {
		std::cerr << "Wrong class instance does not created." << std::endl;
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 5. Other tests */
	std::cout << "\n" << BG_BLUE"=============== 5. Other tests. ==============="RESET << std::endl;
	try {
		test_others();
	}
	catch (std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	return 0;
}
