#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int _index;
        static const std::string ADD;
        static const std::string SEARCH;
        static const std::string EXIT;
    public:
        PhoneBook(void){};
        ~PhoneBook(){};
        void processInput(void);
        void search(void);
        void add(void);
};

#endif