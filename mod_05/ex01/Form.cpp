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

Form::Form(const Form &other): _name(other.getName()), \
								_isSigned(other.getSignedAttr()), \
								_reqGradeToSign(other.getGradeToSign()), \
								_reqGradeToExec(other.getGradeToExec()) {
}

const char *Form::GradeTooHighException::what() const throw() {
	return "FORM: Grade Too High Exception is raised";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "FORM: Grade Too Low Exception is raised";
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
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
