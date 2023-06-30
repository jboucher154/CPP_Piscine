
#include "Account.hpp"
#include <iostream>
#include <ctime>

/*CLASS VARIABLES INTIALIZATION*/
int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*CONSTRUCTOR/ DECONSTRUCTOR*/

Account::Account( int initial_deposit ) : 
_amount(initial_deposit), 
_accountIndex (Account::_nbAccounts), 
_nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	if (_amount < 0)
		_amount = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

/*GETTERS*/

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:"<< Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (deposit <= 0)
	{
		std::cout << ";deposit:refused" << std::endl;
		return ;
	}	
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount || withdrawal <= 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}	
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:"<< this->_nbWithdrawals << std::endl;
}

/*PRIVATE STUFFS*/

static void	print_formated_time(int to_format) {
	if (to_format < 10)
		std::cout << "0";
	std::cout << to_format;
}

void	Account::_displayTimestamp( void ) {
	time_t	current_time;
	current_time = time(NULL);

	tm *tl = localtime(&current_time);
	std::cout << "[" << tl->tm_year + 1900 << tl->tm_mon + 1 << tl->tm_mday << "_";
	print_formated_time(tl->tm_hour);
	print_formated_time(tl->tm_min);
	print_formated_time(tl->tm_sec);
	std::cout << "] ";
}

Account::Account( void ) {}
