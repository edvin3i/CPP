#include "includes/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}


int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp( void ) {

	std::time_t rawtime = std::time(nullptr);
	std::tm* timeinfo = std::localtime(&rawtime);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "]";
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << (_amount + deposit);
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (_amount < withdrawal) {
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused";
		std::cout << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << (_amount + withdrawal);
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return true;
}

int Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
