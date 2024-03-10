#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <string>

class Contact {
public:

/*	Init	*/
	Contact();
	~Contact();

/*	Setters	*/
	void setFirstName(const std::string &firstname);
	void setLastName(const std::string &lastname);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phonenumber);
	void setDarkestSecret(const std::string &darkestsecret);

/*	Getters	*/
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;


private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

#endif
