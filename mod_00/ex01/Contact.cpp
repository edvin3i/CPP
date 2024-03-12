#include "includes/Contact.hpp"

/*	Init	*/

Contact::Contact() {
}

Contact::~Contact() {
}

/*	Setters	*/

void Contact::setFirstName(const std::string &first_name) {
	firstName = first_name;
}

void Contact::setLastName(const std::string &last_name) {
	lastName = last_name;
}

void Contact::setNickname(const std::string &nick_name) {
	nickName = nick_name;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
	phoneNumber = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret) {
	darkestSecret = darkest_secret;
}

/*	Getters	*/

std::string Contact::getFirstName() const {
	return firstName;
}

std::string Contact::getLastName() const {
	return lastName;
}

std::string Contact::getNickname() const {
	return nickName;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret;
}
