#include "includes/PhoneBook.hpp"


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