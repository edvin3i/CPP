#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void test_exec_low_robot() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat bob("Bob", 8);
	Bureaucrat carry("Carry", 54);
	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	RobotomyRequestForm wall("Concrete Wall");
	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << wall;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	bob.signForm(wall);
	std::cout << BG_BRIGHT_BLACK"\n-=== Review form after signing ===-"RESET << std::endl;
	std::cout << wall;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	carry.executeForm(wall);
	std::cout << BG_BRIGHT_BLACK"\n-=== Destructors ===-"RESET << std::endl;
}

void test_sign_robot() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat alice("Alice", 8);
	Bureaucrat john("John", 5);
	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	RobotomyRequestForm wall("Concrete Wall");
	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << wall;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	alice.signForm(wall);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << wall;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	john.executeForm(wall);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;
}

void test_exec_low_shrub() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat jolie("Jolie", 111);
	Bureaucrat mary("Mary", 146);
	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	ShrubberyCreationForm back_yard("FrontYard");
	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << back_yard;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	jolie.signForm(back_yard);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << back_yard;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	mary.executeForm(back_yard);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;
}

void test_sign_shrub() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat alice("Alice", 8);
	Bureaucrat fleet("Vogon Constructor Fleet", 5);
	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	ShrubberyCreationForm back_yard("BackYard");
	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << back_yard;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	alice.signForm(back_yard);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << back_yard;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	fleet.executeForm(back_yard);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;
}

void test_exec_low_pres() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat jolie("Jolie", 111);
	Bureaucrat mary("Mary", 146);
	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	PresidentialPardonForm pardon_form("Ford Prefect");
	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << pardon_form;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	jolie.signForm(pardon_form);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << pardon_form;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	mary.executeForm(pardon_form);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;
}

void test_sign_pres() {
	std::cout << BG_BRIGHT_BLACK"-=== Create bureaucrats ===-"RESET << std::endl;
	Bureaucrat kwaltz("Kwaltz", 8);
	Bureaucrat jeltz("Prostetnic Vogon Jeltz", 5);
	std::cout << BG_BRIGHT_BLACK"-=== Create form ===-"RESET << std::endl;
	PresidentialPardonForm pardon_form("Arthur Dent");
	std::cout << BG_BRIGHT_BLACK"-=== Review form before signing ===-"RESET << std::endl;
	std::cout << pardon_form;
	std::cout << BG_BRIGHT_BLACK"-=== Sign the form ===-"RESET << std::endl;
	kwaltz.signForm(pardon_form);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Review form after signing ===-"RESET << std::endl;
	std::cout << pardon_form;
	std::cout << BG_BRIGHT_BLACK"-=== Try to execute the form ===-"RESET << std::endl;
	jeltz.executeForm(pardon_form);
	std::cout << "\n" << BG_BRIGHT_BLACK"-=== Destructors ===-"RESET << std::endl;
}

int main() {

	/* 1. Try to exec with low grade	*/
	std::cout << "\n" << BG_BLUE"=============== 1. Test low grade execution of RobotomyRequestForm ==============="RESET << std::endl;
	test_exec_low_robot();

	/* 2. Try to sign and execute with grades enough	*/
	std::cout << "\n" << BG_BLUE"=============== 2. Test execution RobotomyRequestForm with enough grade ==============="RESET << std::endl;
	test_sign_robot();

	/* 3. Try to sign and execute with grades enough	*/
	std::cout << "\n" << BG_BLUE"=============== 2. Test execution ShrubberyCreationForm with enough grade ==============="RESET << std::endl;
	test_sign_shrub();

	/* 4. Try to exec with low grade	*/
	std::cout << "\n" << BG_BLUE"=============== 4. Test low grade execution of ShrubberyCreationForm ==============="RESET << std::endl;
	test_exec_low_shrub();

	/* 5. Try to exec with low grade	*/
	std::cout << "\n" << BG_BLUE"=============== 5. Test low grade execution of PresidentialPardonForm ==============="RESET << std::endl;
	test_exec_low_pres();

	/* 6. Try to sign and execute with grades enough	*/
	std::cout << "\n" << BG_BLUE"=============== 6. Test execution PresidentialPardonForm with enough grade ==============="RESET << std::endl;
	test_sign_pres();

	return 0;
}
