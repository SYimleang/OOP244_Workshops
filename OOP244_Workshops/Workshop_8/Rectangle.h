/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// Rectangle Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize header file of Rectangle module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__

#include <iostream>
#include "LblShape.h"

using namespace std;

namespace sdds {

	class Rectangle : public LblShape {

		int m_width;		// Variable to hold the width of the Shape.
		int m_height;		// Variable to hold the height of the Shape.
	public:

		Rectangle();											// Default constructor
		Rectangle(const char* label, int width, int height);	// Constructor with three arguments
		~Rectangle();											// Destructor

		void getSpecs(istream& in);		// Function for get content from input.
		void draw(ostream& os) const;	// Function for print the content.

	};
}
#endif