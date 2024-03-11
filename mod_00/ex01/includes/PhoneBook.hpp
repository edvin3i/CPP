#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
public:

	PhoneBook();
	~PhoneBook();

	void addContact(std::string firstname,
					std::string lastname,
					std::string nickname,
					std::string phonenumber,
					std::string darkestsecret);
	void searchContact();
	void exit();

private:

	int currentSize;
	static const int maxSize = 8;

	Contact contacts[maxSize];

	void displayContacts();
};

#endif