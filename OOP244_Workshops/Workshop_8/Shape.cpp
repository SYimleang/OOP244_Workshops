/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// Shape module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize Shape module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Shape.h"

using namespace std;
namespace sdds {

	/* Overload extraction operator to print content from draw() function in the Shape class. */
	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}

	/* Overload insertion operator to get content from getSpec() function in the Shape class. */
	istream& operator>>(istream& in, Shape& shape) {
		shape.getSpecs(in);
		return in;
	}

}
