/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang May 31, 2023	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/


#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	// Sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	// Sets the Item to a recognizable safe Empty State.
	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0.0;
	}

	// Sets attributes by using arguments
	void Item::set(const char* name, double price, bool taxed) {
		// If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state
		if (name == nullptr || price < 0) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	// Print items in formatted
	void Item::display()const {
		// If Item is Valid, then display m_itemName, m_price and m_taxed
		if (isValid()) {
			cout << "| "; 
			
			//left - justified in 20 spaces, padded with '.' (dots)
			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout << " | ";
			cout.unsetf(ios::left);
			
			
			//right - justified in 7 spaces with two digits after the decimal point
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;
			cout << " | ";

			//if m_taxed is true prints "Yes" otherwise prints "No "
			if(m_taxed == true) { cout << "Yes";}
			else{ cout << "No ";}
			cout << " |" << endl;	
		}
		// If item is Invalid
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

	// Validate items
	bool Item::isValid()const {
		bool flag = false;
		if (m_itemName != nullptr && m_itemName[0] != '\0' && m_price > 0.0) {
			flag = true;
		}
		return flag;
	}

	// Return m_price which private member
	double Item::price()const {
		return m_price;
	}

	// Return taxed calculated
	double Item::tax()const {
		double taxRate = 0.13;
		double taxed;
		// If the m_taxed is false, return 0.0
		if (!m_taxed) {
			taxed = 0.0;
		}
		// If the m_taxed is true, return m_price*taxRate
		else {
			taxed = m_price * taxRate;
		}
		return taxed;
	}
}