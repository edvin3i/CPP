#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	Intern &operator=(const Intern &other);
	Intern(const Intern &other);
	virtual ~Intern();

	AForm *makeForm(std::string form_name, std::string target);

	class InternDoesntKnowThisForm: public std::exception {
	public:
		const char *what() const throw();
	};

	class TargetNameIsEmpty: public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif
