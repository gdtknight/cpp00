#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

/*
 * [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
 */
void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";"
            << "total:" << _totalAmount << ";"
            << "deposits:" << _totalNbDeposits << ";"
            << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

/*
 * [19920104_091532] index:0;amount:42;created
 */
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created" << std::endl;

  _nbAccounts++;
  _totalAmount += initial_deposit;
}

/*
 * [19920104_091532] index:0;amount:47;closed
 */
Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed" << std::endl;
  _nbAccounts--;
  _totalAmount -= _amount;
}

/*
 * [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
 */
void Account::makeDeposit(int deposit) {
  int p_amount = _amount;

  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << p_amount << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << std::endl;
}

// clang-format off
/*
 * [19920104_091532] index:0;p_amount:47;withdrawal:refused
 * [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
 */
// clang-format on
bool Account::makeWithdrawal(int withdrawal) {
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";";

  if (_amount - withdrawal < 0) {
    std::cout << "withdrawal:" << "refused" << ";" << std::endl;
    return (false);
  }
  _amount -= withdrawal;
  _nbWithdrawals++;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  std::cout << "withdrawal:" << withdrawal << ";"
            << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount(void) const { return (_amount); }

/*
 * [19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
 */
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  char buffer[80];
  time_t now = time(nullptr);
  struct tm *local = localtime(&now);
  strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local);
  std::cout << buffer;
}
