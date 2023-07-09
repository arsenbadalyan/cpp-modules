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

int Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
    return (EXIT_SUCCESS);
}

int Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
    return (EXIT_SUCCESS);
}

int Contact::setNickname(std::string nickname) {
    this->_nickname = nickname;
    return (EXIT_SUCCESS);
}

int Contact::setPhone(std::string phone) {
    for(int i = 0; phone[i]; i++)
        if(!isdigit(phone[i]))
            return (EXIT_FAILURE);
    this->_phone = phone;
    return (EXIT_SUCCESS);
}

int Contact::setSecret(std::string secret) {
    this->_secret = secret;
    return (EXIT_SUCCESS);
}