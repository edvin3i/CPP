#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:

	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact();

	/* Test methods */
/*
	void addContact(const Contact &newContact);
	void addTestContacts();
*/


private:

	int					_current_size;
	static const int	_max_size = 8;

	Contact				contacts[_max_size];

	int askContactIndex();
	void askFieldValue(int w, std::string *field, std::string msg);
	void displayContactsAll() const;
	void displayContact(int index) const;
};

#endif
