/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// LblShape module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 18, 2023	Initialize LblShape module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "LblShape.h"

using namespace std;
namespace sdds {

	/*==============PRIVATE METHOD===============*/
	/* Function to set the value to m_label. */
	void LblShape::set(const char* label) {

		// Dynamic allocating m_label and copy content from received parameter content.
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}

	/*==============PROTECTED METHOD===============*/
	/* Returns the unmodifiable value of m_label member variable. */
	char* LblShape::label() const{
		return m_label;
	}

	/*================PUBLIC METHOD================*/
	/* Default constructor. */
	LblShape::LblShape() {
		m_label = nullptr;
	}

	/* Constructor with one parameter. */ 
	LblShape::LblShape(const char* label) {

		// Dynamic allocating m_label and copy content from received parameter content.
		set(label);
	}

	/* Destructor. */
	LblShape::~LblShape() {
		delete[] m_label;
	}

	/* Function to reads a comma - delimited Cstring form istream. */ 
	void LblShape::getSpecs(istream& in) {

		// Sets input variable.
		char input[1000] = {};

		// Receive a Cstring (a label) from istream up to the ',' character
		in.getline(input, 1000, ',');

		// Deallocate previous content of m_label, Dynamic allocating m_label and copy content from received parameter content.
		delete[] m_label;
		m_label = new char[strlen(input) + 1];
		strcpy(m_label, input);
	}
	
	// Implement nothing.
	void LblShape::draw(ostream& os) const {
		
	}

}
