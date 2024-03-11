#include "includes/PhoneBook.hpp"
#include <iostream>
#include <iomanip>


PhoneBook::PhoneBook(): currentSize(0) {

}

PhoneBook::~PhoneBook() {

}

void PhoneBook::askFieldValue(int w, std::string *field, std::string msg) {

	while (!field || *field == "") {
		std::cout << std::setw(w) << msg;
		std::cin >> *field;
	}
}

void PhoneBook::addContact() {

	int fwidth = 17;

	std::string firstname;
	askFieldValue(fwidth, &firstname, "First Name: ");

	std::string lastname;
	askFieldValue(fwidth, &lastname, "Last Name: ");

	std::string nickname;
	askFieldValue(fwidth, &nickname, "Nickname: ");

	std::string phonenumber;
	askFieldValue(fwidth, &phonenumber, "Phone Number: ");

	std::string darkestsecret;
	askFieldValue(fwidth, &darkestsecret, "Darkest Secret: ");

	if (currentSize < maxSize) {
		contacts[currentSize].setFirstName(firstname);
		contacts[currentSize].setLastName(lastname);
		contacts[currentSize].setNickname(nickname);
		contacts[currentSize].setPhoneNumber(phonenumber);
		contacts[currentSize].setDarkestSecret(darkestsecret);
		currentSize++;
	} else {
		return ;
	}
}

void PhoneBook::searchContact() {
	displayContacts();

}

void PhoneBook::displayContacts() {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "FirstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int index = 0; index < maxSize; ++index)
	{
		std::cout << "|" << std::setw(10) << index << "|";



		std::string firstname = contacts[index].getFirstName();
		std::string lastname = contacts[index].getLastName();
		std::string nickname = contacts[index].getNickname();

		if (firstname.length() > 10) {
			firstname = firstname.substr(0, 9) + ".";
		}

		if (lastname.length() > 10) {
			lastname = lastname.substr(0, 9) + ".";
		}

		if (nickname.length() > 10) {
			nickname = nickname.substr(0, 9) + ".";
		}

		std::cout << std::setw(10) << firstname << "|";
		std::cout << std::setw(10) << lastname << "|";
		std::cout << std::setw(10) << nickname << "|";
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

	}
}