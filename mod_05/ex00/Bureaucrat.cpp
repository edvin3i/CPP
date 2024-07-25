#include "includes/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): _name("NameLess"), _grade(75) {

	std::cout << "\nNameless bureaucrat " \
 << BRIGHT_WHITE" with grade " \
 << BRIGHT_MAGENTA << this->_grade \
 << RESET" is created!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "\nBureaucrat " \
 << BRIGHT_BLUE << this->_name \
 << BRIGHT_WHITE" with grade " \
 << BRIGHT_MAGENTA << this->_grade \
 << RESET" is created!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incGrade() {
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
	std::cout << this->_name << "'s grade has been incremented to the " << \
								this->_grade << "." << std::endl;
}

void Bureaucrat::decGrade() {
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
	std::cout << this->_name << "'s grade has been decremented to the " << \
								this->_grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "\nBureaucrat "BRIGHT_BLUE << this->_name \
 << RESET" was "BRIGHT_RED << "FIRED!!!11"RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
	out << "\n" << obj.getName() << ", bureaucrat _grade " << \
			obj.getGrade() << "." << std::endl;
	return (out);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low Exception is raised";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High Exception is raised";
}

