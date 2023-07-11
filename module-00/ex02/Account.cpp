#include <iostream>
#include "Account.hpp"

// Constructor and Destructor
Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

// Class static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Getters
int Account::getNbAccounts( void ) {return (Account::_nbAccounts);}
int Account::getTotalAmount( void ) {return (Account::_totalAmount);}
int Account::getNbDeposits( void ) {return (Account::_totalNbDeposits);}
int	Account::getNbWithdrawals( void ) {return (Account::_totalNbWithdrawals);}
int Account::checkAmount( void ) const {return (this->_amount);}

void Account::_displayTimestamp( void ) {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << buffer << " ";
}

// Display accounts info
void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// Other member functions
void Account::makeDeposit( int deposit ) {
	const int oldAmount = this->_amount;

	// Changing total data
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	// Changing current customer data
	this->_nbDeposits++;
	this->_amount += deposit;

	// Log printing
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << oldAmount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	const int oldAmount = this->_amount;
	bool isRefused = false;

	// Check if withdrawal more than amount refuse deal
	if ((oldAmount - withdrawal) < 0)
		isRefused = true;
	if (!isRefused) {
		// Changing total data
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		// Changing current customer data
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
	}
	// Log printing
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << oldAmount << ";";
	if (isRefused) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

// Display current status
void Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}