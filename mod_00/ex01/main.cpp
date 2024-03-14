#include "includes/PhoneBook.hpp"

int main() {

	bool flag = true;
	std::string prompt;

	PhoneBook pb;

	/* Test data init
	 * pb.addTestContacts();
	 */

	while(flag) {

		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		std::cin >> prompt;
		std::cout << prompt << std::endl;

		if (prompt == "EXIT") {
			flag = false;
		}
		else if (prompt == "SEARCH") {
			pb.searchContact();
		}
		else if (prompt == "ADD") {
			pb.addContact();
		}
		else {
			std::cout << "Command not found!" << std::endl;
			continue ;
		}
	}
	return 0;
}
