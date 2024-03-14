#pragma once
#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Contact {
public:

/*	Init	*/
	Contact();
	~Contact();

/*	Setters	*/
	void setFirstName(const std::string &first_name);
	void setLastName(const std::string &last_name);
	void setNickname(const std::string &nick_name);
	void setPhoneNumber(const std::string &phone_number);
	void setDarkestSecret(const std::string &darkest_secret);

/*	Getters	*/
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;


private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
