#include "PhoneBook.hpp"

static void drawTableRow(std::string const col1, std::string const col2, std::string const col3, std::string const col4);
static std::string modifyInfo(std::string info);

const std::string PhoneBook::ADD = "ADD";
const std::string PhoneBook::SEARCH = "SEARCH";
const std::string PhoneBook::EXIT = "EXIT";

// getters
int PhoneBook::getIndex( void ) const { return (this->_index); }
int PhoneBook::getSize( void ) const { return (this->_size); }

PhoneBook::PhoneBook(void) {
	this->_index = 0;
	this->_size = 0;
}

Contact PhoneBook::add(void) {
    Contact contact;
	std::string input;

    std::cout << std::endl << "Contact Info" << std::endl;
    do { std::cout << "Enter First Name: "; getline(std::cin, input); } while (!contact.setFirstName(input));
    do { std::cout << "Enter Last Name: "; getline(std::cin, input); } while (!contact.setLastName(input));
	do { std::cout << "Enter Nickname: "; getline(std::cin, input); } while (!contact.setNickname(input));
	do { std::cout << "Enter Phone number: "; getline(std::cin, input); } while (!contact.setPhone(input));
	do { std::cout << "Enter your darkest secret: "; getline(std::cin, input); } while (!contact.setSecret(input));
    return contact;
}

void PhoneBook::processInput(void) {
    std::string input;

    while (1) {
        std::cout << std::endl << "Please type one of commands: [ADD] | [SEARCH] | [EXIT]" << std::endl;
        std::cout << "Your input: ";
		getline(std::cin, input);
		
        if (input == PhoneBook::EXIT)
            return ;
        if (input == PhoneBook::ADD) {
			this->_contacts[this->_index] = this->add();
			this->nextIndex();
		}
        if (input == PhoneBook::SEARCH) {
			if (this->getSize() > 0)
				search();
			else
				std::cout  << std::endl << "! WARNING !" << std::endl << "There is no contacts to show. Please add new contacts with [ADD] command." << std::endl << std::endl;
		}
    }
    return ;
}

void PhoneBook::nextIndex(void) {
	this->_index++;
	if (this->_size < CONTACTS_MAX_SIZE)
		this->_size++;
	if (this->_index >= CONTACTS_MAX_SIZE)
		this->_index = 0;
	return ;
}

static void drawTableRow(std::string const col1, std::string const col2, std::string const col3, std::string const col4) {
	std::cout << "|" << std::setw(TABLE_LENGTH) << col1;
	std::cout << "|" << std::setw(TABLE_LENGTH) << col2;
	std::cout << "|" << std::setw(TABLE_LENGTH) << col3;
	std::cout << "|" << std::setw(TABLE_LENGTH) << col4;
	std::cout << "|" << std::endl;
	return ;
}

static std::string modifyInfo(std::string info) {
	return (info.size() >= TABLE_LENGTH ? (info.substr(0, TABLE_LENGTH - 1) + '.') : info);
}

void PhoneBook::displayTable(void) {
	Contact curContact;

	std::cout << std::endl;
	drawTableRow("index", "first name", "last name", "nickname");
	for (int i = 0; i < this->getSize(); i++) {
		curContact = this->_contacts[i];
		drawTableRow(
				std::to_string(i + 1),
				modifyInfo(curContact.getFirstName()),
				modifyInfo(curContact.getLastName()),
				modifyInfo(curContact.getNickname())
		);
	}
	std::cout << std::endl;
	return ;
}

bool PhoneBook::displayContact(std::string index) {
	Contact contact;
	int numIndex;

	for (int i = 0; index[i]; i++)
		if (!isdigit(index[i]))
			return (false);
	numIndex = std::atoi(index.c_str());
	if (numIndex < 1 || numIndex > this->getSize())
		return (false);
	contact = this->_contacts[numIndex - 1];
	std::cout << std::endl << "DETAILED INFO" << std::endl;
	std::cout << "    First Name: " << contact.getFirstName() << std::endl;
	std::cout << "     Last Name: " << contact.getLastName() << std::endl;
	std::cout << "      Nickname: " << contact.getNickname() << std::endl;
	std::cout << "  Phone Number: " << contact.getPhone() << std::endl;
	std::cout << "Darkest Secret: " << contact.getSecret() << std::endl;
	std::cout << std::endl;
	return (true);
}

void PhoneBook::search(void) {
	std::string index;

	this->displayTable();
	std::cout << "! INFO: You can enter [EXIT] to go back to menu !" << std::endl << std::endl;
	std::cout << "Enter one of table indexes to watch full data: ";
	std::cin >> index;
	std::cin.clear();
	std::cin.ignore();
	if (index == PhoneBook::EXIT)
		return ;
	if (!this->displayContact(index))
		this->search();
	return ;
}