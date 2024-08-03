#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
		AForm("PresidentialPardonForm", 25, 5),
														_target("NameLess") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
		AForm(target, 25, 5),
															_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
										AForm(other), _target(other.getTarget()) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\nPresidentialPardonForm "BRIGHT_BLUE << this->getName() \
 				<< RESET" was "BRIGHT_RED << "destroyed!"RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		this->_target = other.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::doAction() const {
	std::cout << BRIGHT_MAGENTA << this->_target \
	<< RESET" has been pardoned by Zaphod Beeblebrox." << std::endl;
}

