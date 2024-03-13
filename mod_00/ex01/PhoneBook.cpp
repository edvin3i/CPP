#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): current_size(0) {

}

PhoneBook::~PhoneBook() {

}

void PhoneBook::askFieldValue(int w, std::string *field, std::string msg) {

	std::cout << std::setw(w) << msg;
	std::getline(std::cin, *field);

	while (!field || *field == "") {
		std::getline(std::cin, *field);
	}
}

void PhoneBook::addContact() {

	int fld_width = 17;
	int next_index = current_size % max_size;

	std::string first_name;
	askFieldValue(fld_width, &first_name, "First Name: ");

	std::string last_name;
	askFieldValue(fld_width, &last_name, "Last Name: ");

	std::string nickname;
	askFieldValue(fld_width, &nickname, "Nickname: ");

	std::string phone_number;
	askFieldValue(fld_width, &phone_number, "Phone Number: ");

	std::string darkest_secret;
	askFieldValue(fld_width, &darkest_secret, "Darkest Secret: ");

	contacts[next_index].setFirstName(first_name);
	contacts[next_index].setLastName(last_name);
	contacts[next_index].setNickname(nickname);
	contacts[next_index].setPhoneNumber(phone_number);
	contacts[next_index].setDarkestSecret(darkest_secret);

	current_size++;
}

int PhoneBook::askContactIndex() {

	int index = -1;
	std::string input;

	while (index < 0 || index > 7) {

		std::cout << "Enter the contact's index (0 - 7): ";
		std::cin >> input;

		if (std::all_of(input.begin(), input.end(), ::isdigit)) {

			index = std::stoi(input);

			if (index < 0 || index > 7) {

				std::cout << "Index out of range!" << std::endl;
				continue ;

			}
			else {
				break ;
			}
		}
		else {
			std::cout << "Invalid input!" << std::endl;
		}
	}

	std::cout << index;
	std::cout << std::endl;

	return index;
}

void PhoneBook::displayContact(int index) const {

	int fld_width = 17;

	std::cout << std::setw(fld_width) << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << std::setw(fld_width) << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << std::setw(fld_width) << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << std::setw(fld_width) << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << std::setw(fld_width) << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;

}

void PhoneBook::searchContact() {
	int index;

	displayContactsAll();
	index = askContactIndex();
	displayContact(index);

}

void PhoneBook::displayContactsAll() const {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int index = 0; index < max_size; ++index)
	{
		std::cout << "|" << std::setw(10) << index << "|";
		std::string first_name = contacts[index].getFirstName();
		std::string last_name = contacts[index].getLastName();
		std::string nickname = contacts[index].getNickname();

		if (first_name.length() > 10) {
			first_name = first_name.substr(0, 9) + ".";
		}

		if (last_name.length() > 10) {
			last_name = last_name.substr(0, 9) + ".";
		}

		if (nickname.length() > 10) {
			nickname = nickname.substr(0, 9) + ".";
		}

		std::cout << std::setw(10) << first_name << "|";
		std::cout << std::setw(10) << last_name << "|";
		std::cout << std::setw(10) << nickname << "|";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

	}
}

/* Test methods */
/*

void PhoneBook::addContact(const Contact &newContact) {

	if (current_size < max_size) {
		contacts[current_size++] = newContact;
	} else {
		return ;
	}
}

void PhoneBook::addTestContacts() {

	std::string testFirstNames[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hank"};
	std::string testLastNames[] = {"Johnson", "Smith", "Doe", "Brown", "White", "Black", "King", "Wright"};
	std::string testNicknames[] = {"Ally", "Bobby", "Chuck", "Dave", "Evie", "Frankie", "Gracie", "Hankie"};
	std::string testPhoneNumbers[] = {"123-456-789", "987-654-321", "555-555-555", "111-222-333", "444-555-666", "777-888-999", "000-111-222", "333-444-555"};
	std::string testDarkestSecrets[] = {"I love C++", "I use tabs over spaces", "I don't like pizza", "I never finished 'Hello World'", "I dream in code", "I prefer Python", "I like dark mode", "I use light mode"};

	for (int i = 0; i < 8; ++i) {

		Contact newContact;

		newContact.setFirstName(testFirstNames[i]);
		newContact.setLastName(testLastNames[i]);
		newContact.setNickname(testNicknames[i]);
		newContact.setPhoneNumber(testPhoneNumbers[i]);
		newContact.setDarkestSecret(testDarkestSecrets[i]);

		addContact(newContact);
	}
}
*/
