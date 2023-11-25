/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 4, 2023    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

	// Adds all the calorie of the foods using a loop and returns the sum.
	int CalorieList::totalCalorie()const {
		int sum = 0;
		for (int i = 0; i < m_size; i++) {
			if (m_food[i].isValid()) {
				sum += m_food[i].calorie();
			}
		}
		return sum;
	}

	// Print the title of the list
	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;

		// If the list is valid, then print "Daily Calorie Consumption"
		if (isValid()) {
		cout << "|  Daily Calorie Consumption                         |" << endl;
		}

		// If the list is invalid, then print "Invalid Calorie Consumption list"
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	// Print footer of the list
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;

		// If the list is valid, then print summary of the list
		if (isValid()) {
			cout << "|    Total Calories for today:";
			cout.fill(' ');
			cout.width(9);
			cout.setf(ios::right);
			cout << totalCalorie() << " |            |" << endl;
		}
		// If the bill is invalid, then print "Invalid Calorie Consumption list"
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	// Validate list
	bool CalorieList::isValid()const {
		bool flag = false;
		int i;
		//Check m_food are valid. 
		//Then loop through all the Food in the m_food array and make sure they are all valid.
		if (m_food != nullptr) {

			for (i = 0; i < m_size; i++) {
				if (m_food[i].isValid()) {
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		return flag;
	}

	// sets the CalorieList to accept the "size" number of Food Items. 
	// This function is called to prepare the CalorieList for accepting food items
	void CalorieList::init(int size){

		// Dynamic allocation the Food
		m_food = new Food[size];

		// Sets m_size to input size, reset m_foodAdded to 0 and sets Food to empty state
		int i;
		m_size = size;
		m_foodsAdded = 0;

		for (i = 0; i < m_size; i++) {
			m_food[i].setEmpty();

		}
	}

	// Adds Food Items using their Name, Calorie count and time of consumption up to 
	// the number set in the init() function, returns true if successful.
	bool CalorieList::add(const char* item_name, int calories, int when){
		bool result = false;

		// If the number of added foodAdded is less than the length of the m_size array, then return true
		if (m_foodsAdded < m_size) {
			if (calories < 0 || calories > 3000) {
				cout << "Incalid calories. Calories must be between 0 to 3000" << endl;
			}
			else {
				m_food[m_foodsAdded].set(item_name, calories, when);
				m_foodsAdded++;
				result = true;
			}
		}
		return result;
	}

	// Displays the report with food information and the total calorie consumed in the day
	// as shown in the report sample
	void CalorieList::display()const {
		Title();
			for (int i = 0; i < m_size; i++) {
			m_food[i].display();
		}
		footer();
	}

	// Releases all the memory used. After this function init() can be called for another
	// report;
	void CalorieList::deallocate() {
		delete[] m_food;
		m_food = nullptr;
	}
}