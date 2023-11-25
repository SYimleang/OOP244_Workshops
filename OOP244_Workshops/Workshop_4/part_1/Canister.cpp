/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// Canister Module program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 7, 2023    Create the Canister calculation program
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265

using namespace std;
namespace sdds {

	// Sets the attributes to their default values.
	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}
   
	// Sets the content name of the current Canister.
	void Canister::setName(const char* Cstr) {

		// If received agument is not NULL and m_usable is true, then call clear function to deallocate memory and sets m_contentName to nullptr. Otherwise, it will silently do nothing.
		if (Cstr != nullptr && m_usable == true) {
			clear();

			// Dynamic allocating the m_contentName.
			m_contentName = new char[strLen(Cstr) + 1];

			// Copies the Cstr into the newly allocated memory.
			strCpy(m_contentName, Cstr);
		}
	}

	// Checks volume of canister
	bool Canister::isEmpty()const {
		bool flag = false;

		// Returns true is the content volume is less than 0.00001
		if (m_contentVolume < 0.00001) {
			flag = true;
		}
		return flag;
	}

	// Compares the content name of this Canister with the received argument
	bool Canister::hasSameContent(const Canister& C)const {
		bool flag = false;

		// if both content names are not null and are identical, then return true.
		if (strCmp(C.m_contentName, m_contentName) == 0 && m_contentName != nullptr && C.m_contentName != nullptr) {
			flag = true;
		}

		return flag;
	}

	// The default constructor
	Canister::Canister() {
		setToDefault();			// Sets to default values.
	}

	// The one argument constructor
	Canister::Canister(const char* contentName) {
		setToDefault();				// Sets to default values.
		setName(contentName);	// Sets content name to received argument.
	}

	// The three arguments constructor
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();		// Sets to default values.

		// If received arguments are acceptable, then sets members to corresponding argument values.
		if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}

		// Otherwise, sets m_usable to false.
		else {
			m_usable = false;
		}
	}

	// The destructor
	Canister::~Canister() {
		clear();
	}

	// Sets the Content name of the canister
	Canister& Canister::setContent(const char* contentName) {

		// If received argument is NULL, then sets to unusable.
		if (contentName == nullptr) {
			m_usable = false;
		}

		// Else if the Canister is empty (checks volumn), then set the name of Canister to received argument
		else if (isEmpty()) {
			setName(contentName);
		}

		// Else if the Canister is not empty, then checks name of the Canister and received argument is same.
		else if (strCmp(m_contentName, contentName) != 0) {
			m_usable = false;
		}
		return *this;
	}

	// Adds the quantity argument to the content volume of the Canister if the quantity fits in the Canister.
	Canister& Canister::pour(double quantity) {

		// Checks if the Canister is usable and the quantity is more than zero and if the sum of the quantity and the volume() is less than or equal to the capacity(), add the quantity to the content volume.
		if ((m_usable = true && quantity > 0) && (capacity() > (quantity + volume()))) {
			m_contentVolume += quantity;
		}

		// Otherwise render the Canister unusable and then returns the reference of the current object.
		else {
			m_usable = false;
		}
		return *this;
	}

	// Pours the content of the Canister argument into the current Canister.
	Canister& Canister::pour(Canister& C) {

		// Set the content name to the Canister argument using setContent().
		setContent(C.m_contentName);

		// Pour the whole volume but still has some left in canister
		// If the volume() of the argument is greater than the capacity() minus the volume().
		if (C.volume() > (capacity() - volume())) {

			// Reduce the content volume of the argument by capacity() minus volume().
			C.m_contentVolume -= (capacity() - volume());
			// Sets the content volume to capacity().
			m_contentVolume = capacity();
		}

		// Pour the whole volume until empty
		// Else pour the content volume of the argument using pour() methodand set the content volume of the argument to 0.0.
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}

		return *this;
	}

	// Returns the content volume attribute.
	double Canister::volume()const {
		return m_contentVolume;
	}

	std::ostream& Canister::display()const {

		// Display Capacity
		cout.setf(ios::fixed);
		cout.width(7);
		cout.setf(ios::right);
		cout.precision(1);
		cout << capacity() << "cc (";

		// Display Dimensions
		cout << m_height << "x" << m_diameter << ") Canister";

		if (m_usable == false) {
			cout << " of Unusable content, discard!";
		}
		else if(m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			cout.precision(1);
			cout.setf(ios::right);
			cout << m_contentVolume << "cc   ";
			cout << m_contentName;
		}
		
		return cout;
	}

	// Calculate the capacity and return the result.
	double Canister::capacity()const {
		double results = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
		return results;
	}

	// Clears an unusable Canister back to an empty Canister
	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
}