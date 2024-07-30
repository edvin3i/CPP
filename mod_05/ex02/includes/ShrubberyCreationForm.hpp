#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	std::string getTarget() const;
	void execute(Bureaucrat const &executor) const;

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &obj);

#endif
