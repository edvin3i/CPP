#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BRIGHT_BLACK   "\033[90m"
#define BG_BRIGHT_BLACK   "\033[100m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

class Bureaucrat {

private:
	const std::string name;
	int	grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat& other);
	Bureaucrat(const Bureaucrat &operator);
	~Bureaucrat();

	void incGrade(void);
	void decGrade(void);

	std::string getName(void) const;
	std::string getGrade(void) const;

	class GradeTooHighException: public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
