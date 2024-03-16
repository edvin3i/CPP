#include "includes/Harl.hpp"

std::string getTestComplaint(void) {
	std::cout << "Enter type of complaint (DEBUG, INFO, WARNING, ERROR etc.) or exit: ";
	std::string input;
	std::getline(std::cin, input);
	return input;
}

int main() {

	Harl harl;

	std::cout << "Test output:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	std::cout << "End of test output\n" << std::endl;

	std::string input;
	while (true)
	{
		input = getTestComplaint();
		if (!input.compare("exit"))
			break ;
		harl.complain(input);
		std::cout << std::endl;
	}
	return 0;
}