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
#include "Bill.h"
using namespace std;
namespace sdds {

	// Adds all the taxes of the items using a loop and returns the sum.
	double Bill::totalTax()const {
		double sum = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i].isValid()) {
				sum += m_items[i].tax();
			}
		}
		return sum;
	}

	// Adds all the prices of the items using a loopand returns the sum.
	double Bill::totalPrice()const {
		double sum = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i].isValid()) {
				sum += m_items[i].price();
			}
		}
		return sum;
	}

	// Print the title of the bill
	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;

		// If the bill is valid, then print title name of the bill
		if (isValid()) {
			cout << "| ";
			cout.fill(' ');
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title << " |" << endl;	//left - justified in 36 spaces
			cout.unsetf(ios::left);
		}
		
		// If the bill is invalid, then print "Invalid Bill"
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	// Print footer of the bill
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;

		// If the bill is valid, then print summary of the bill
		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.fill(' ');
			cout.width(10);
			cout.precision(2);
			cout << totalTax() << " |" << endl;
			cout << "|              Total Price: ";
			cout.fill(' ');
			cout.width(10);
			cout.precision(2);
			cout << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.fill(' ');
			cout.width(10);
			cout.precision(2);
			cout << totalTax() + totalPrice() << " |" << endl;
		}

		// If the bill is invalid, then print "Invalid Bill"
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	// Sets the Bill object to an empty state
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	// Validate bill
	bool Bill::isValid()const {
		bool flag = false;
		int i;
		//hint: First check and make sure m_title and m_items are valid. 
		//Then loop through all the Items in the m_items array and make sure they are all valid.
		if (m_title[0] != '\0' || m_items != nullptr) {
			
			for (i = 0; i < m_noOfItems;i++) {
				if (m_items[i].isValid()) {
					flag = true;
				}
				else
				{
					flag = false;
				}
			}
		}
		return flag;
	}

	// set the m_noOfItems member variable to the incoming corresponding argument and sets m_itemsAdded to zero.
	// If If any of the arguments are invalid, it will set the Bill to an empty state.
	void Bill::init(const char* title, int noOfItems) {
		m_items = new Item[noOfItems];
		// If any of the arguments are invalid, it will set the Bill to an empty state.
		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		}

		// Else sets m_noOfItems, m_itemAdded and copy string to m_title and dynamically allocate an array of Items pointed by m_items member variable.
		else {
			int i;
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);

			for (i = 0; i < m_noOfItems;i++) {
				m_items[i].setEmpty();
			}
			
		}
	}

	// Sets the next available subject to the incoming argument values.
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool result = false;

		// If the number of added Items is less than the length of the m_items array
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			result = true;
		}
		return result;
	}

	//
	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}