#include <iostream>
#include <iomanip>
#include "includes/PhoneBook.hpp"

int main()
{
	int flag = 1;
	std::string prompt;
	PhoneBook pb;
	//pb.searchContact();

	while(flag) {
		std::cout << "Enter command: ";
		std::cin >> prompt;
		std::cout << std::endl;
		std::cout << prompt << std::endl;
		if (prompt == "EXIT") {
			flag = 0;
		} else if (prompt == "SEARCH") {
			pb.searchContact();
		} else if (prompt == "ADD") {
			pb.addContact();
		}
	}
	return 0;
}