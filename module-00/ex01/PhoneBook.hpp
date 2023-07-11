#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

# define CONTACTS_MAX_SIZE 8
# define TABLE_LENGTH 10
class PhoneBook {
    private:
        Contact _contacts[CONTACTS_MAX_SIZE];
        int _index;
        static const std::string ADD;
        static const std::string SEARCH;
        static const std::string EXIT;
		void nextIndex(void);
    public:
        PhoneBook(void);
        ~PhoneBook(){};
		int getIndex(void);
        void processInput(void);
		void displayTable(void);
		bool displayContact(std::string index);
        void search(void);
        Contact add(void);
};

#endif