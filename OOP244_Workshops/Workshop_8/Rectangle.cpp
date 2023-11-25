/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// Rectangle module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize Rectangle module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Rectangle.h"

using namespace std;
namespace sdds {
	
	/*================PUBLIC METHOD================*/
	/* Sets the width and height member variables to zero,
	and invokes the default constructor of the base class. */
	Rectangle::Rectangle() : LblShape(){
		m_width = 0;
		m_height = 0;
	}

	/* Constructor. Receives a Cstring for the label, and two values 
	for the width and height of the Rectangle from the argument list. */
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
		m_width = width;
		m_height = height;
	}

	/* Destructor. This class has no destructor implemented. */
	Rectangle::~Rectangle() {

	}

	/* function to reads comma-separated specs of the Line from istream. */
	void Rectangle::getSpecs(istream& in) {

		// Call the getSpecs function of the base class.
		LblShape::getSpecs(in);

		// Read two comma-separated values for m_width and m_height from the istream
		in >> m_width;
		in.ignore(1000, ','); // Ignore the comma

		in >> m_height;
		in.ignore(1000, '\n'); // Ignore The rest of the characters up to and including the newline character '\n'.
	}

	/* This function overrides the draw function of the base class to print the output as format of Reactangle. */
	void Rectangle::draw(ostream& os) const{

		// Assign the length of label to a variable.
		int length = strlen(LblShape::label());		

		// If the label is not empty and width, height is more than minimum value for printing, then print the content as format.
		if (LblShape::label() != nullptr && m_height >= 3 && m_width >= (length + 2)) {

			int ndx;
			// First line
			cout << '+';
			for (ndx = 1; ndx < (m_width - 1); ndx++) {
				cout << '-';
			}
			cout << '+' << endl;

			// Second line
			cout << '|';
			cout << label();
			for (int i = 0; i < (m_width - length - 2); ++i) {
				cout << ' ';
			}
			cout << '|' << endl;

			// Space lines (height - 3)
			int ndxH, ndxW;
			for (ndxH = 0; ndxH < (m_height - 3); ndxH++) {
				cout << '|';
				for (ndxW = 0; ndxW < m_width - 2; ndxW++) {
					cout << ' ';
				}
				cout << '|' << endl;
			}

			// Last line (same as first line)
			cout << '+';
			for (ndx = 1; ndx < (m_width - 1); ndx++) {
				cout << '-';
			}
			cout << '+';
		}
	}

}
