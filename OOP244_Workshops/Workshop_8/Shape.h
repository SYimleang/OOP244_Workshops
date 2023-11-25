/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// Shape Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize header file of Shape module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__

#include <iostream>

using namespace std;

namespace sdds {

	class Shape {
	public:
		virtual ~Shape() = default;	// Virtual empty destructor for the shape interface.

		virtual void getSpecs(istream& in) = 0;		// Virtual function for get content.
		virtual void draw(ostream& os) const = 0;	// Virtual function for print the content.
	};

	ostream& operator<<(ostream& os, const Shape& shape);	//Overload Extraction operator
	istream& operator>>(istream& in, Shape& shape);			//Overload Insertion operator
}
#endif