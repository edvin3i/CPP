#include "includes/Bureaucrat.hpp"
#include "Intern.hpp"

void test_intern_form_robotomy() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat alice("Alice", 8);
	Bureaucrat john("John", 5);

	AForm *ffm1;
	Intern intern;

	ffm1 = intern.makeForm("robotomy request", "Bender");

	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << *ffm1;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	alice.signForm(*ffm1);
	std::cout << BG_BRIGHT_BLACK"\n-=== Review form after signing ===-"RESET << std::endl;
	std::cout << *ffm1;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	john.executeForm(*ffm1);
	std::cout << BG_BRIGHT_BLACK"\n-=== Destructors ===-"RESET << std::endl;

	delete ffm1;

}

void test_intern_form_shrubbery() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat eric("Eric Bartlett", 95);
	Bureaucrat fleet("Vogon Constructor Fleet", 15);

	AForm *ffm2;
	Intern intern;

	ffm2 = intern.makeForm("shrubbery creation", "Garden");

	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << *ffm2;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	eric.signForm(*ffm2);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << *ffm2;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	fleet.executeForm(*ffm2);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;

	delete ffm2;
}

void test_intern_form_pres() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat kwaltz("Kwaltz", 8);
	Bureaucrat jeltz("Prostetnic Vogon Jeltz", 5);

	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	AForm *ffm3;
	Intern intern;

	ffm3 = intern.makeForm("presidential pardon", "Ford Prefect");

	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << *ffm3;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	kwaltz.signForm(*ffm3);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << *ffm3;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	jeltz.executeForm(*ffm3);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;

	delete ffm3;
}

void test_intern_unknown_form() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat marvin("Marvin", 145);
	Bureaucrat tricia("Tricia", 149);

	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	AForm *some_form;
	Intern intern;

	some_form = intern.makeForm("some paper", "Some Target");

	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << *some_form;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	marvin.signForm(*some_form);
	std::cout << BG_BRIGHT_BLACK"\n-=== Review form after signing ===-"RESET << std::endl;
	std::cout << *some_form;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	tricia.executeForm(*some_form);
	std::cout << BG_BRIGHT_BLACK"\n-=== Destructors ===-"RESET << std::endl;

	delete some_form;
}

void test_intern_empty_target_name() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat marvin("Marvin", 145);
	Bureaucrat tricia("Tricia", 149);

	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	AForm *ffm4;
	Intern intern;

	ffm4 = intern.makeForm("shrubbery creation", "");

	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << *ffm4;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	marvin.signForm(*ffm4);
	std::cout << BG_BRIGHT_BLACK"\n-=== Review form after signing ===-"RESET << std::endl;
	std::cout << *ffm4;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	tricia.executeForm(*ffm4);
	std::cout << BG_BRIGHT_BLACK"\n-=== Destructors ===-"RESET << std::endl;

	delete ffm4;
}

int main() {

	std::cout << "\n" << BG_BLUE"=============== 1. Test intern creation RobotomyRequestForm ==============="RESET << std::endl;
	try {
		test_intern_form_robotomy();
	}
	catch(std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BG_BLUE"=============== 2. Test intern creation ShrubberyCreationForm ==============="RESET << std::endl;
	try {
		test_intern_form_shrubbery();
	}
	catch(std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BG_BLUE"=============== 3. Test intern creation PresidentialPardonForm ==============="RESET << std::endl;
	try {
		test_intern_form_pres();
	}
	catch(std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BG_BLUE"=============== 4. Test intern creation UnknownForm ==============="RESET << std::endl;
	try {
		test_intern_unknown_form();
	}
	catch(std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BG_BLUE"=============== 5. Test intern creation form with empty name ==============="RESET << std::endl;
	try {
		test_intern_empty_target_name();
	}
	catch(std::exception &e) {
		std::cerr << BG_BRIGHT_RED << BRIGHT_YELLOW << e.what() << RESET << std::endl;
	}


	return 0;
}
