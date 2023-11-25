/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 1
// Version 1.0
// Description
// Account program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 14, 2023   Initialize basic create and transaction program
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {

    // Set the account to invalid empty state
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    // Constructor. Set the account to new state
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    // Overload constructor. Set the account valid state by assign the account number and balance.
    Account::Account(int number, double balance) {

        // First set to invalid empty state
        setEmpty();

        // If the account number is valid and the balance is correct, then set the account number and balance to received values
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    // Display the account detail as the format.
    std::ostream& Account::display() const {

        // Checks that account is in valid state
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }

        // Checks that account is in new state
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }

        // Otherwise. (Account is in invalid empty state)
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    // Overload boolean variable type. Return true if the the account is valid
    Account::operator bool() const {
        return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
    }

    // Overload integer variable type. Return account number
    Account::operator int() const {
        return m_number;
    }

    // Overload double variable type. Return balance value
    Account::operator double() const {
        return m_balance;
    }

    // Overload ~ operator. Return true if the accout is in New or Not Set state
    bool Account::operator~() const {
        return m_number == 0;
    }

    // Overload the = operator. Sets the account number to integer number.
    Account& Account::operator=(int number) {

        // If number is invalid, then set account to invalid empty state.
        if (number < 10000 || number > 99999) {
            setEmpty();
        }

        // Else if account is in new state, then set account number to this number. Otherwise do nothing.
        else if (m_number == 0) {
            m_number = number;
        }
        return *this;
    }

    // Overload the = operator. Move account number and account balance from right account to left account
    Account& Account::operator=(Account& another) {

        if (m_number == 0 && another.m_number >= 10000 && another.m_number <= 99999) {
            m_number = another.m_number;
            m_balance = another.m_balance;
            another.m_number = 0;
            another.m_balance = 0.0;
        }
        return *this;
    }

    // Overload the += operator. If account is in an valid state or received value is not negative value, then add m_balance by received value. Otherwise, do nothing.
    Account& Account::operator+=(double value) {
        if (m_number >= 0 && value >= 0.0) {
            m_balance += value;
        }
        return *this;
    }

    // Overload the -= operator. If account is in an valid state or received value is not negative value or not more than m_balance, then reduce m_balance by received value. Otherwise, do nothing.
    Account& Account::operator-=(double value) {
        if (m_number >= 0 && value >= 0.0 && m_balance >= value) {
            m_balance -= value;
        }
        return *this;
    }

    // Overload the << operator. If both account is valid and not same account number, then move balance of right account to left account. Otherwise, do nothing. 
    Account& Account::operator<<(Account& other_account) {
        if (m_number != other_account.m_number && m_number > 0 && other_account.m_balance > 0) {
            m_balance += other_account.m_balance;
            other_account.m_balance = 0.0;
        }
        return *this;
    }

    // Overload the >> operator. If both account are valid and not same account number, then move balance of left account to right account.Otherwise, do nothing.
    Account& Account::operator>>(Account& other_account) {
        if (m_number != other_account.m_number && m_balance > 0) {
            other_account.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

    // Overload the + helper operator. If both account are valid then return sum of both balance. Otherwise return 0.
    double operator+(const Account& left, const Account& right) {

        if ((int)left > 0 && (int)right > 0) {
            return (double)left + (double)right;
        }
        return 0.0;
    }

    // Overload the += helper operator. Add m_balance value of this object to m_balance of left object.
    double operator+=(double& left, const Account& right) {
        return left += double(right);
    }
}


