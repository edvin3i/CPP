#include "includes/PhoneBook.hpp"
#include <iostream>
#include <iomanip>


PhoneBook::PhoneBook(): currentSize(0) {

}

PhoneBook::~PhoneBook() {

}

void PhoneBook::addContact() {

	std::string firstname;
	std::cout << std::setw(17) << "First Name: ";
	std::cin >> firstname;
	std::string lastname;
	std::cout << std::setw(17) << "Last Name: ";
	std::cin >> lastname;
	std::string nickname;
	std::cout << std::setw(17) << "Nickname: ";
	std::cin >> nickname;
	std::string phonenumber;
	std::cout << std::setw(17) << "Phone Number: ";
	std::cin >> phonenumber;
	std::string dearkestsecret;
	std::cout << std::setw(17) << "Darkest Secret: ";
	std::cin >> dearkestsecret;

	if (currentSize < maxSize) {
		contacts[currentSize].setFirstName(firstname);
		contacts[currentSize].setLastName(lastname);
		contacts[currentSize].setNickname(nickname);
		contacts[currentSize].setPhoneNumber(phonenumber);
		contacts[currentSize].setDarkestSecret(dearkestsecret);
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