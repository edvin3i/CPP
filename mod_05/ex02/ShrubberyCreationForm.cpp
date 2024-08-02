#include "includes/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():
		AForm("ShrubberyCreationForm", 145, 137), \
														_target("NameLess") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
		AForm(target, 145, 137), \
														_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
		AForm(other), _target(other.getTarget()) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\nShrubberyCreationForm "BRIGHT_BLUE << this->getName() \
 				<< RESET" was "BRIGHT_RED << "destroyed!"RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		this->_target = other.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

const char *ShrubberyCreationForm::FileOpenError::what() const throw() {
	return "FILE: Error with opening file!";
}

void ShrubberyCreationForm::doAction() const {
	std::string filename = "ShrubsOn" + this->getName();
	std::ofstream plant(filename.c_str());
	if (!plant.is_open()) {
		throw FileOpenError();
	}


	plant << "                      ccee88oo\n";
	plant << "                   C8O8O8Q8PoOb o8oo\n";
	plant << "                dOB69QO8PdUOpugoO9bD\n";
	plant << "               CgggbU8OU qOp qOdoUOdcb\n";
	plant << "                   6OuU  /p u gcoUodpP\n";
	plant << "                      \\\\//  /douUP\n";
	plant << "                        \\\\////\n";
	plant << "                         |||/\\\n";
	plant << "                         |||\\/\n";
	plant << "                         |||||\n";
	plant << "                   .....//||||\\....\n";
	plant << "\n";
	plant << "              ccee88oo                        ccee88oo\n";
	plant << "           C8O8O8Q8PoOb o8oo              C8O8O8Q8PoOb o8oo\n";
	plant << "        dOB69QO8PdUOpugoO9bD           dOB69QO8PdUOpugoO9bD\n";
	plant << "       CgggbU8OU qOp qOdoUOdcb        CgggbU8OU qOp qOdoUOdcb\n";
	plant << "           6OuU  /p u gcoUodpP            6OuU  /p u gcoUodpP\n";
	plant << "              \\\\//  /douUP                  \\\\//  /douUP\n";
	plant << "                \\\\////                       \\\\////\n";
	plant << "                 |||/\\                         |||/\\\n";
	plant << "                 |||\\/                         |||\\/\n";
	plant << "                 |||||                         |||||\n";
	plant << "           .....//||||\\....               .....//||||\\....\n";

	plant.close();

	std::cout << "\nFile " << filename << " was created.\n" << std::endl;
}

