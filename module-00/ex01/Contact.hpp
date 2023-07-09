#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
    public:
        Contact(void){};
        ~Contact(){};
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getPhone(void);
        std::string getSecret(void);
        int setFirstName(std::string firstName);
        int setLastName(std::string lastName);
        int setNickname(std::string nickname);
        int setPhone(std::string phone);
        int setSecret(std::string phone);
};
#endif