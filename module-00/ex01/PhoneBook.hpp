#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

# define CONTACTS_MAX_SIZE 8
# define TABLE_LENGTH 10
class PhoneBook {

public:

	// Constructors and destructors
	PhoneBook(void);
	~PhoneBook(){};

	// Getters
	int getIndex(void) const;
	int getSize(void) const;

	// Methods
	void processInput(void);
	void displayTable(void);
	bool displayContact(std::string index);

	void search(void);
	Contact add(void);

private:
	
	int _index;
	int _size;
	Contact _contacts[CONTACTS_MAX_SIZE];
	
	static const std::string ADD;
	static const std::string SEARCH;
	static const std::string EXIT;
	
	void nextIndex(void);

};

#endif