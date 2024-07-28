#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

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
	AForm d163("Anketa", 50, 75);
	std::cout << d163;
	alice.signForm(d163);
}

void test_sign() {
	Bureaucrat bob("Bob", 9);
	AForm f028b("F-028B", 15, 30);
	std::cout << f028b;
	bob.signForm(f028b);
	std::cout << f028b;
}

void test_deep_copy() {
	AForm f1("F0-001", 10, 50);
	AForm f2("F1-002", 15, 60);
	AForm f3(f1);

	std::cout << "AForm 1 address: " << &f1 << std::endl;
	std::cout << f1;
	std::cout << "AForm 2 address: " << &f2 << std::endl;
	std::cout << f2;
	std::cout << "AForm 3 address: " << &f3 << std::endl;
	std::cout << f3;
}
void test_equal_operator() {
	Bureaucrat john("John", 5);

	AForm f1("Source form", 10, 20);
	std::cout << f1;
	john.signForm(f1);
	std::cout << f1;

	AForm f2("Destination form", 1, 3);
	std::cout << f2;

	std::cout << BG_BRIGHT_BLACK"Desination = Source:"RESET << std::endl;
	f2 = f1;
	std::cout << f2;

}

int main() {

	/* Check the edges	*/
	/* 1. Try to sign with low grade	*/
	std::cout << "\n" << BG_BLUE"=============== 1. Test low grade sign ==============="RESET << std::endl;
	test_sign_low();

	/* 2. Try to sign with grade enough	*/
	std::cout << "\n" << BG_BLUE"=============== 2. Test sign ==============="RESET << std::endl;
	test_sign();

	/* 3. Deep copy test */
	std::cout << "\n" << BG_BLUE"=============== 3. Deep copy test. ==============="RESET << std::endl;
	test_deep_copy();

	/* 4. Equal test */
	std::cout << "\n" << BG_BLUE"=============== 4. Equal test. ==============="RESET << std::endl;
	test_equal_operator();

	return 0;
}
