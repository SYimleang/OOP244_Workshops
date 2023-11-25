/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// Line module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize Line module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Line.h"

using namespace std;
namespace sdds {

	/*================PUBLIC METHOD================*/
	/* Default constructot. Sets the m_length member variable to zero, 
	and invokes the default constructor of the base class.*/
	Line::Line() :LblShape() {
		m_length = 0;
	}

	/* Constructor. Passes the Cstring to the constructor of the base class
	and sets the m_length member variable to the value of the second argument.*/
	Line::Line(const char* label, int length) : LblShape(label) {
		m_length = length;
	}

	/* Destructor. This class has no destructor implemented. */
	Line::~Line() {

	}

	/* function to reads comma-separated specs of the Line from istream. */
	void Line::getSpecs(istream& in) {

		// Call the getSpecs function of the base class.
		LblShape::getSpecs(in);

		// Read the value of the m_length attribute from the istream.
		in >> m_length;

		// Ignore The rest of the characters up to and including the newline character '\n'.
		in.ignore(1000, '\n');
	}

	/* This function overrides the draw function of the base class to print the output as format of Line. */
	void Line::draw(ostream& os) const {

		int ndx;

		if (m_length > 0 && LblShape::label() != nullptr) {
			os << LblShape::label() << endl;
			
			for (ndx = 0; ndx < m_length; ndx++) {
				os << "=";
			}
		}
	}
}
