#include "includes/Bureaucrat.hpp"

void print_bureaucrat(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > 75) {
		std::cout << BRIGHT_YELLOW << bureaucrat << RESET << std::endl;
	}
	else {
		std::cout << GREEN << bureaucrat << RESET << std::endl;
	}
	return ;
}

int main(void) {

	/* Check the edges	*/
	/* 1. Bottom edge		*/
	std::cout << "\n" << BG_BLUE"=============== 1. Bottom edge ==============="RESET << std::endl;
	try {
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
	catch (const std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 2. Top edge	*/
	std::cout << "\n" << BG_BLUE"=============== 2. Top edge ==============="RESET << std::endl;
	try {
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
	catch (const std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 3. Create the class instance with a wrong init value (LOW)	*/
	std::cout << "\n" << BG_BLUE"=============== 3. Wrong class instance (LOW) ==============="RESET << std::endl;
	try {
		Bureaucrat wolfgang("Wolfgang", 0);
	}
	catch (const std::exception &e){
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	/* 4. Create the class instance with a wrong init value (HIGH)	*/
	std::cout << "\n" << BG_BLUE"=============== 4. Wrong class instance (HIGH) ==============="RESET << std::endl;
	try {
		Bureaucrat zaphod("Zaphod", 1000);
	}
	catch (const std::exception &e){
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	return 0;
}
