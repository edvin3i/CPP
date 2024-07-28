#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string name, int reqGradeToSign, int reqGradeToExec);
	Form &operator=(const Form &other);
	Form(const Form &other);
	~Form();

	void beSigned(Bureaucrat &bureaucrat);

	std::string getName() const;
	bool getSignedAttr() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	class GradeTooHighException: public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char *what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _reqGradeToSign;
	const int _reqGradeToExec;


};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif
