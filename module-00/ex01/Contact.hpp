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
        bool setFirstName(std::string firstName);
        bool setLastName(std::string lastName);
        bool setNickname(std::string nickname);
        bool setPhone(std::string phone);
        bool setSecret(std::string phone);
		static bool isEmpty(std::string line);
};
#endif