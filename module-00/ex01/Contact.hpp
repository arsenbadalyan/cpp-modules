#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
public:

	// Constructors and destructors
	Contact(void){};
	~Contact(){};
	
	// Getters 
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getPhone(void);
	std::string getSecret(void);

	// Setters
	bool setFirstName(std::string firstName);
	bool setLastName(std::string lastName);
	bool setNickname(std::string nickname);
	bool setPhone(std::string phone);
	bool setSecret(std::string phone);

	// Static methods
	static bool isEmpty(std::string line);

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phone;
	std::string _secret;

};
#endif