/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// LblShape Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize header file of LblShape module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__

#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds {

	class LblShape : public Shape {
		char* m_label;
		void set(const char* label);

	protected:
		char* label() const;				// Function to return m_label.

	public:
		LblShape();						// Default constructor.
		LblShape(const char* label);	// Constructor with one argument.
		~LblShape();					// Destructor.

		// Prevent copying or assignment to instances of the class
		LblShape(const LblShape& src) = delete;				// Prevent copying.
		LblShape& operator=(const LblShape& src) = delete;	// Prevent assignment.
		LblShape& operator&() = delete;

		void getSpecs(istream& in);		// Function for get content from input.
		void draw(ostream& os) const;	// Function for print the content.
	};
}
#endif