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

	if (!target.length()) {
		std::cout << BRIGHT_MAGENTA"Intern:"RESET" Hey! You should call me the target name!" \
		<< std::endl;
		throw Intern::TargetNameIsEmpty();
	}

	std::string form_names[] = {"robotomy request", \
								"presidential pardon",  \
								"shrubbery creation"};

	int form_num = 1 * (form_name == form_names[0]) \
			     + 2 * (form_name == form_names[1]) \
				 + 3 * (form_name == form_names[2]);

	switch (form_num) {
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		case 3:
			return new ShrubberyCreationForm(target);
		
	}
	std::cout << BRIGHT_MAGENTA"Intern:"RESET" I don't know form named " \
	<< BRIGHT_CYAN << form_name << RESET << "!" << std::endl;
	throw Intern::InternDoesntKnowThisForm();
}

const char *Intern::InternDoesntKnowThisForm::what() const throw() {
	return "Unknow Form Error!";
}

const char *Intern::TargetNameIsEmpty::what() const throw() {
	return "Empty TargetName Error!";
}