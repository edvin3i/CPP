#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
public:

	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact();
	void exit();

private:

	int currentSize;
	static const int maxSize = 8;

	Contact contacts[maxSize];

	void askFieldValue(int w, std::string *field, std::string msg);
	void displayContacts();
};

#endif