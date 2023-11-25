/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// Label maker program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 11, 2023   Program for create the label
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"

namespace sdds {
	class LabelMaker {
		int m_noOfLabel;
		Label* m_label;

	public:
		LabelMaker();				// Constructor
		LabelMaker(int noOfLabels);	//Constructor with number of labels
		void readLabels();			// Function for get input from user
		void printLabels();			// Function for prints the label
		~LabelMaker();				// Destructor
	};
}

#endif
