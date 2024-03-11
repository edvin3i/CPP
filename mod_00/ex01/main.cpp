#include <iostream>
#include "includes/PhoneBook.hpp"

int main()
{
	using std::string;
	using std::cin;


	string firstname;
	string lastname;
	string nickname;
	string phonenumber;
	string darkestsecret;

	PhoneBook pb;
/*
	cin >> firstname;
	cin >> lastname;
	cin >> nickname;
	cin >> phonenumber;
	cin >> darkestsecret;

	pb.addContact(firstname, lastname, nickname, phonenumber, darkestsecret);*/

	pb.searchContact();

	return 0;
}