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

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != other)
		this->_target = other.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	try {
		executor.executeF
	}
}

PresidentialPardonForm::getTarget() {
	return this->_target;
}