#include "includes/Account.hpp"

Account::Account(int initial_deposit) {

}

Account::~Account( void ) {

}

static int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

static int Account::getTotalAmount( void ) {
	return _totalAmount;
}

static int Account::getNbDeposits( void ) {
	return _nbDeposits;
}

static int Account::getNbWithdrawals( void ) {
	return _nbWithdrawals;
}

static void Accounts::displayAccountsInfos( void ) {

}

static void Account::_displayTimestamp( void ) {

}

void Account::makeDeposit(int deposit) {

}

bool Account::makeWithdrawal(int withdrawal) {

}

int Account::checkAmount( void ) const {

}

void Account::displayStatus() const {

}