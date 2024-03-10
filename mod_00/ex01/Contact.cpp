#include "includes/Contact.hpp"

/*	Init	*/

Contact::Contact() {
}

Contact::~Contact() {
}

/*	Setters	*/

void Contact::setFirstName(const std::string &firstname) {
	FirstName = firstname;
}

void Contact::setLastName(const std::string &lastname) {
	LastName = lastname;
}

void Contact::setNickname(const std::string &nickname) {
	Nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phonenumber) {
	PhoneNumber = phonenumber;
}

void Contact::setDarkestSecret(const std::string &darkestsecret) {
	DarkestSecret = darkestsecret;
}

/*	Getters	*/

std::string Contact::getFirstName() const {
	return FirstName;
}

std::string Contact::getLastName() const {
	return LastName;
}

std::string Contact::getNickname() const {
	return Nickname;
}

std::string Contact::getPhoneNumber() const {
	return PhoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return DarkestSecret;
}
