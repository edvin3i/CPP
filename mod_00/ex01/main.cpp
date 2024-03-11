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
			std::string firstname;
			std::cout << std::setw(15) << "First Name: ";
			std::cin >> firstname;
			std::string lastname;
			std::cout << std::setw(15) << "Last Name: ";
			std::cin >> lastname;
			std::string nickname;
			std::cout << std::setw(15) << "Nickname: ";
			std::cin >> nickname;
			std::string phonenumber;
			std::cout << std::setw(15) << "Phone Number: ";
			std::cin >> phonenumber;
			std::string dearkestsecret;
			std::cout << std::setw(15) << "Darkest Secret: ";
			std::cin >> dearkestsecret;

			pb.addContact(firstname, \
							lastname, \
							nickname, \
							phonenumber, \
							dearkestsecret);
		}
	}
	return 0;
}