#include "includes/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), \
			_target("NameLess") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137), \
			_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
		AForm(other), _target(other.getTarget()) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		this->_target = other.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return std::string();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

}
