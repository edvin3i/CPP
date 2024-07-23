#include "includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	this->name = other.getName();
	this->grade = other.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

std::string Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incGrade() {
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
	std::cout << this->name << "'s grade has been incremented to the " << \
								this->grade << "." << std::endl;
}

void Bureaucrat::decGrade() {
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
	std::cout << this->name << "'s grade has been decremented to the " << \
								this->grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat() {
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
	out << obj.getName() << ", bureaucrat grade " << \
			obj.getGrade() << "." << std::endl;
	return (out);
}

const char Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low Exception is raised";
}

const char Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High Exception is raised";
}

