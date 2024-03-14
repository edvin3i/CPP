#include "includes/Contact.hpp"

/*	Init	*/

Contact::Contact() {
}

Contact::~Contact() {
}

/*	Setters	*/

void Contact::setFirstName(const std::string &first_name) {
	_firstName = first_name;
}

void Contact::setLastName(const std::string &last_name) {
	_lastName = last_name;
}

void Contact::setNickname(const std::string &nick_name) {
	_nickName = nick_name;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
	_phoneNumber = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret) {
	_darkestSecret = darkest_secret;
}

/*	Getters	*/

std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getNickname() const {
	return _nickName;
}

std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}
