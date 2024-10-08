#include "includes/AForm.hpp"


AForm::AForm(): _name("NameLess"), _isSigned(false), \
				_reqGradeToSign(50), _reqGradeToExec(75) {

}

AForm::AForm(std::string name, int reqGradeToSign, int reqGradeToExec): \
			_name(name), _isSigned(false), \
			_reqGradeToSign(reqGradeToSign), _reqGradeToExec(reqGradeToExec) {
	std::cout << "\nForm " \
 				<< BRIGHT_BLUE << this->_name \
 				<< BRIGHT_WHITE" with SIGN grade " \
 				<< BRIGHT_MAGENTA << this->_reqGradeToSign \
				<< BRIGHT_WHITE" with EXEC grade " \
 				<< BRIGHT_MAGENTA << this->_reqGradeToExec \
 				<< RESET" is created!\n" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	if(this != &other)
		this->_isSigned = other.getSignedAttr();
	return *this;
}

AForm::~AForm() {
	std::cout << "\nForm "BRIGHT_BLUE << this->_name \
 				<< RESET" was "BRIGHT_RED << "destroyed!"RESET << std::endl;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSignedAttr() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_reqGradeToSign;
}

int AForm::getGradeToExec() const {
	return this->_reqGradeToExec;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= this->_reqGradeToSign)
		throw AForm::GradeTooLowException();
	else if (bureaucrat.getGrade() < this->_reqGradeToSign)
	this->_isSigned = true;
}

AForm::AForm(const AForm &other): _name(other.getName()), \
								_isSigned(other.getSignedAttr()), \
								_reqGradeToSign(other.getGradeToSign()), \
								_reqGradeToExec(other.getGradeToExec()) {
}

void AForm::execute(const Bureaucrat &exc) const {
	if (exc.getGrade() > this->_reqGradeToExec) {
	/* Error message */
		std::cout << "\n" << BG_BRIGHT_YELLOW"ERROR: " << exc.getName() \
		<< " does not executed the " \
		<< this->_name << " form."RESET << "\n" << std::endl;

		throw AForm::GradeTooLowException();
	}
	else if (!this->_isSigned) {
		/* Error message */
		std::cout << "\n" << BG_BRIGHT_YELLOW"ERROR: " << exc.getName() \
		<< " does not executed the " \
		<< this->_name << " form."RESET << "\n" << std::endl;
		throw AForm::FormIsNotSigned();
	}
	std::cout << "Bureaucrat " << BRIGHT_BLUE << exc.getName() \
	<< RESET" executed the "BRIGHT_MAGENTA << this->getName() \
	<< RESET" form."<< std::endl;

	/* Calling the specified func in the derived class: */
	doAction();

	/* Additional message according the subject */
	std::cout << "\n" << BG_BRIGHT_GREEN << exc.getName() << " executed " \
	<< this->_name << " form."RESET << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "FORM: Grade Too High Exception is raised";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "FORM: Grade Too Low Exception is raised";
}

const char *AForm::FormIsNotSigned::what() const throw() {
	return "FORM: This form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
	out << "\nForm name: " << BRIGHT_CYAN << obj.getName() << RESET \
			<< ".\nSign grade: " \
			<< BRIGHT_GREEN << obj.getGradeToSign() << RESET".\n" \
			<< "Exec grade: " \
			<< BRIGHT_MAGENTA << obj.getGradeToExec() << RESET".\n" << std::endl;
			if (obj.getSignedAttr())
				std::cout << BRIGHT_GREEN"SIGNED\n"RESET << RESET << std::endl;
			else
				std::cout << BRIGHT_RED"NOT SIGNED\n"RESET << RESET << std::endl;
	return (out);
}

