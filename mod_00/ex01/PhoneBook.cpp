#include "includes/PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook(): currentSize(0) {

}

PhoneBook::~PhoneBook() {

}

void PhoneBook::addContact(std::string firstname,
					std::string lastname,
					std::string nickname,
					std::string phonenumber,
					std::string darkestsecret) {

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
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << "     Index" << "|";
	std::cout << " FirstName" << "|";
	std::cout << "  LastName" << "|";
	std::cout << "  Nickname" << "|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int index = 0; index < maxSize; ++index)
	{
		std::cout << "|" << index << "|";
		std::cout << std::endl;
		std::cout << "-------------------------------------------" << std::endl;

	}
}