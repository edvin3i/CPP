#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
		AForm("RobotomyRequestForm", 72, 45), \
														_target("NameLess") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm(target, 72, 45), _target(target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if(this != &other)
		this->_target = other.getTarget();
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
									AForm(other), _target(other.getTarget()) {

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {

}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

