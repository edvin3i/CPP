#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
		AForm("RobotomyRequestForm", 72, 45), \
														_target("NameLess") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
		AForm(target, 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
		AForm(other), _target(other.getTarget()) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if(this != &other)
		this->_target = other.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\nRobotomyRequestForm "BRIGHT_BLUE << this->getName() \
 				<< RESET" was "BRIGHT_RED << "destroyed!"RESET << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::doAction() const {
	std::cout << "\nDrilling noizes: ZrzrzrzrzrzzzzzzzRRRRzZZZZzzzzrz... " << std::endl;
	std::srand(std::time(NULL));
	int abc = std::rand();
	if (abc % 2 == 0) {
		std::cout << this->_target << " has been robotomized " \
		<< BRIGHT_GREEN"successfully."RESET << std::endl;
	} else {
		std::cout << "The robotomy of " << BRIGHT_MAGENTA << this->_target \
		<< RESET" is" << BRIGHT_RED" failed"RESET << "." << std::endl;
	}
}

