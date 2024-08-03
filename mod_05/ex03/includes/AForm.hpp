#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(std::string name, int reqGradeToSign, int reqGradeToExec);
	AForm &operator=(const AForm &other);
	AForm(const AForm &other);
	virtual ~AForm();

	void beSigned(Bureaucrat &bureaucrat);
	virtual void doAction() const = 0;
	virtual void execute(Bureaucrat const &exc) const;

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

	class FormIsNotSigned: public std::exception {
	public:
		const char *what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _reqGradeToSign;
	const int _reqGradeToExec;

};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif
