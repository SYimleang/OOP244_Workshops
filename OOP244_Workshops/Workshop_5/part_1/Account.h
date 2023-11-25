/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 1
// Version 1.0
// Description
// Account header
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 14, 2023   Initialize basic create and transaction program
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int number);
      Account& operator=(Account& m_account);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& other_account);
      Account& operator>>(Account& other_account);
   };
   double operator+(const Account& left, const Account& right);
   double operator+=(double& left, const Account& right);
   
}
#endif // SDDS_ACCOUNT_H_