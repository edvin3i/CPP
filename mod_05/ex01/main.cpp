#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

void print_bureaucrat(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > 75) {
		std::cout << BRIGHT_YELLOW << bureaucrat << RESET << std::endl;
	}
	else {
		std::cout << GREEN << bureaucrat << RESET << std::endl;
	}
}

void test_sign_low() {
	Bureaucrat alice("Alice", 80);
	print_bureaucrat(alice);
	std::cout << BRIGHT_CYAN"First try to increment grade for "BRIGHT_BLUE \
					<< alice.getName() << RESET << std::endl;
	alice.incGrade();
	print_bureaucrat(alice);
	std::cout << BRIGHT_CYAN"Second try to increment grade for "BRIGHT_BLUE \
					<< alice.getName() << RESET << std::endl;
	Form d163("Anketa", 50, 75);
	alice.signForm(d163);
}



void test_others() {
	Bureaucrat b1("Firsty", 10);
	Bureaucrat b2("Secondly", 20);
	Bureaucrat b3(b1);

	std::cout << "B1 address: " << &b1 << std::endl;
	print_bureaucrat(b1);
	std::cout << "B2 address: " << &b2 << std::endl;
	print_bureaucrat(b2);
	std::cout << "B3 address: " << &b3 << std::endl;
	print_bureaucrat(b3);

	std::cout << BG_BRIGHT_BLACK"Lets increase and decrease grades!"RESET << std::endl;
	b2.incGrade();
	print_bureaucrat(b2);
	b3.decGrade();
	print_bureaucrat(b3);

	std::cout << BG_BRIGHT_BLACK"Check final states"RESET << std::endl;
	print_bureaucrat(b1);
	print_bureaucrat(b2);
	print_bureaucrat(b3);
}

int main() {

	/* Check the edges	*/
	/* 1. Bottom edge		*/
	std::cout << "\n" << BG_BLUE"=============== 1. Bottom edge ==============="RESET << std::endl;
	test_sign_low();

	/* 2. Top edge	*/
	std::cout << "\n" << BG_BLUE"=============== 2. Top edge ==============="RESET << std::endl;


	/* 3. Create the class instance with a wrong init value (LOW)	*/
	std::cout << "\n" << BG_BLUE"=============== 3. Wrong class instance (LOW) ==============="RESET << std::endl;

	/* 4. Create the class instance with a wrong init value (HIGH)	*/
	std::cout << "\n" << BG_BLUE"=============== 4. Wrong class instance (HIGH) ==============="RESET << std::endl;

	/* 5. Other tests */
	std::cout << "\n" << BG_BLUE"=============== 5. Other tests. ==============="RESET << std::endl;
	/*try {
		test_others();
	}
	catch (std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}*/

	return 0;
}
