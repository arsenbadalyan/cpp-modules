#include "Contact.hpp"

std::string Contact::getFirstName(void) {
    return (this->_firstName);
}

std::string Contact::getLastName(void) {
    return (this->_lastName);
}

std::string Contact::getNickname(void) {
    return (this->_nickname);
}

std::string Contact::getPhone(void) {
    return (this->_phone);
}

std::string Contact::getSecret(void) {
    return (this->_secret);
}

bool Contact::setFirstName(std::string firstName) {
	if (Contact::isEmpty(firstName))
		return (false);
    this->_firstName = firstName;
    return (true);
}

bool Contact::setLastName(std::string lastName) {
	if (Contact::isEmpty(lastName))
		return (false);
    this->_lastName = lastName;
    return (true);
}

bool Contact::setNickname(std::string nickname) {
	if (Contact::isEmpty(nickname))
		return (false);
    this->_nickname = nickname;
    return (true);
}

bool Contact::setPhone(std::string phone) {
    if (Contact::isEmpty(phone))
		return (false);
	for(int i = 0; phone[i]; i++)
        if(!isdigit(phone[i]))
            return (false);
    this->_phone = phone;
    return (true);
}

bool Contact::setSecret(std::string secret) {
    this->_secret = secret;
    return (true);
}

bool Contact::isEmpty(std::string line) {
	if (!line.size())
		return (true);
	for (int i = 0; line[i]; i++)
		if((line[i] < 9 || line[i] > 13) && line[i] != 32)
			return (false);
	return (true);
}