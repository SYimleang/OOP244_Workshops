/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// Line Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize header file of Line module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__

#include <iostream>
#include "LblShape.h"

using namespace std;

namespace sdds {
	class Line : public LblShape {

		int m_length;		// Variable to hold the length of the Line in characters.

	public:
		Line();									// Default constructor
		Line(const char* label, int lenght);	// Constructor with two arguments
		~Line();								// Destructor

		void getSpecs(istream& in);		// Function for get content from input.
		void draw(ostream& os) const;	// Function for print the content.
	};

}
#endif