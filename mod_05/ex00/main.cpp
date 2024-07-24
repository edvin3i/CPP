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

int main() {
	try {
		Bureaucrat alice("Alice", 3);
		print_bureaucrat(alice);
		std::cout << BRIGHT_CYAN << "First try to increment grade for " << RESET << alice.getName() << std::endl;
		alice.incGrade();
		print_bureaucrat(alice);
		std::cout << BRIGHT_CYAN << "Second try to increment grade for " << RESET << alice.getName() << std::endl;
		alice.incGrade();
		print_bureaucrat(alice);
		std::cout << BRIGHT_CYAN << "Third try to increment grade for " << RESET << alice.getName() << std::endl;
		alice.incGrade();
		print_bureaucrat(alice);
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << BG_BRIGHT_BLACK << BRIGHT_RED << e.what() << RESET << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 148);
		print_bureaucrat(bob);
		std::cout << BRIGHT_CYAN << "First try to decrement grade for " << RESET << bob.getName() << std::endl;
		bob.decGrade();
		print_bureaucrat(bob);
		std::cout << BRIGHT_CYAN << "Second try to decrement grade for " << RESET << bob.getName() << std::endl;
		bob.decGrade();
		print_bureaucrat(bob);
		std::cout << BRIGHT_CYAN << "Third try to decrement grade for " << RESET << bob.getName() << std::endl;
		bob.decGrade();
		print_bureaucrat(bob);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << BG_BRIGHT_BLACK << BRIGHT_RED << e.what() << RESET << std::endl;
	}
	
	return 0;
}
