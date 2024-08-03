#include "includes/Intern.hpp"

Intern::Intern() {

}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern::~Intern() {
	std::cout << "\nThe intern quit and probably found a normal job." << std::endl;
}

AForm *Intern::makeForm(std::string form_name, std::string target) {

	if (!target.length())
		throw Intern::TargetNameIsEmpty();

	int form_num = 1 * (form_name == "robotomy request") \
			     + 2 * (form_name == "presidential pardon") \
				 + 3 * (form_name == "shrubbery creation");

	switch (form_num) {
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		case 3:
			return new ShrubberyCreationForm(target);
		
	}

	throw Intern::InternDoesntKnowThisForm();
}

const char *Intern::InternDoesntKnowThisForm::what() const throw() {
	return "Intern: I don't know this form!";
}

const char *Intern::TargetNameIsEmpty::what() const throw() {
	return "Intern: Hey! You should call me the target name!";
}