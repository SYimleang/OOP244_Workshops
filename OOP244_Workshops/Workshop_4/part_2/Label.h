/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// Label header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 11, 2023   Program for create the label
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {
	class Label {
		char* m_content;
		char* m_frame;

		void setToDefault();								// Function for sets m_content and m_frame to default
		void setLabel(const char* frameArg = nullptr, const char* content = nullptr);	// Function for sets m_content and m_frame to received parameter

	public:
		Label();											// Constructor
		Label(const char* frameArg);						// Constructor that received frame parameter
		Label(const char* frameArg, const char* content);	// Constructor that received frame and content parameters
		~Label();											// Destructor
		void readLabel();									// Function for get input from user
		std::ostream& printLabel()const;					// Function for prints the label in formatted
	};
}

#endif
