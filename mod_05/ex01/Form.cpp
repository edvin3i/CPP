#include "includes/Form.hpp"


Form::Form(): _name("NameLess"), _isSigned(false), \
				_reqGradeToSign(50), _reqGradeToExec(75) {

}

Form::Form(std::string name, int reqGradeToSign, int reqGradeToExec): \
			_name(name), _isSigned(false), \
			_reqGradeToSign(reqGradeToSign), _reqGradeToExec(reqGradeToExec) {
}

Form& Form::operator=(const Form &other) {
	if(this != &other)
		this->_isSigned = other.getSignedAttr();
	return *this;
}

Form::~Form() {
	std::cout << "\nForm "BRIGHT_BLUE << this->_name \
 				<< RESET" was "BRIGHT_RED << "destroyed!"RESET << std::endl;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSignedAttr() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_reqGradeToSign;
}

int Form::getGradeToExec() const {
	return this->_reqGradeToExec;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= this->_reqGradeToSign)
		throw Form::GradeTooLowException();
	else if (bureaucrat.getGrade() < this->_reqGradeToSign)
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "FORM: Grade Too High Exception is raised";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "FORM: Grade Too Low Exception is raised";
}
