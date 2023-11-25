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
#include "Food.h"

using namespace std;
namespace sdds {

	// Sets the foodName member Cstring variable to a the Cstring in the name argument up to 30 characters.
	void Food::setName(const char* name) {
		strnCpy(foodName, name, 30);
		foodName[30] = '\0';
	}

	// Sets the Food to a recognizable safe Empty State.
	void Food::setEmpty() {
		foodName[0] = '\0';
		foodCalorie = 0;
	}

	// Sets attributes by using arguments
	void Food::set(const char* name, int calorie, int time) {
		// If calorie is less than 0 or name is null, then the Food is set to a recognizable invalid empty state
		if (name == nullptr || calorie < 0) {
			setEmpty();
		}
		else {
			setName(name);
			foodCalorie = calorie;
			consumpTime = time;
		}
	}

	// Print food items in formatted
	void Food::display()const {
		// If Food is Valid, then display foodName, calorie and comsumption time
		if (isValid()) {
			cout << "| ";

			//Print Name
			//left - justified in 30 spaces, padded with '.' (dots)
			cout.fill('.');										
			cout.width(30);										
			cout.setf(ios::left);
			cout << foodName;
			cout << " | ";
			cout.unsetf(ios::left);

			// Print Calorie
			//right - justified in 4 spaces.
			cout.fill(' ');
			cout.width(4);
			cout.setf(ios::fixed);
			cout << foodCalorie;
			cout << " | ";

			//Print consumption time
			//Checks and print consumption time follow the consumpTime index
			if (consumpTime == 1) {
				cout << "Breakfast ";
			}else if (consumpTime == 2) {
				cout << "Lunch     ";
			}
			else if (consumpTime == 3) {
				cout << "Dinner    ";
			}
			else if (consumpTime == 4){
				cout << "Snack     ";
			}
			cout << " |" << endl;
		}
		// If food item is Invalid
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	// Validate food items
	bool Food::isValid()const {
		bool flag = false;
		if (foodName[0] != '\0' && foodName != nullptr && foodCalorie > 0 && consumpTime > 0 && consumpTime <= 4 ) {
			flag = true;
		}
		return flag;
	}

	// Return foodCalorie which private member
	int Food::calorie()const {
		return foodCalorie;
	}


}