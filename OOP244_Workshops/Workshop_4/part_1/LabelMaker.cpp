/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// Label maker header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 11, 2023   Program for create the label
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "LabelMaker.h"

using namespace std;
namespace sdds {
	
	// Constructor
	LabelMaker::LabelMaker(){
		m_label = nullptr;
	}

	// Creates a dynamic array of Labels to the size of noOfLabels
	LabelMaker::LabelMaker(int noOfLabels) {
		m_noOfLabel = noOfLabels;
		m_label = new Label[noOfLabels];
	}

	// Destructor
	LabelMaker::~LabelMaker() {
		delete[] m_label;
	}

	// Function to read input from the user
	void LabelMaker::readLabels() {

		// print total number of labels
		cout << "Enter " << m_noOfLabel << " labels:" << endl;

		// Looping for input label content
		for (int i = 0; i < m_noOfLabel; i++) {
			cout << "Enter label number " << i + 1 << endl;

			// Call reaLabel function to get input from user
			m_label[i].readLabel();
		}
	}

	// Print all the label content
	void LabelMaker::printLabels() {
		for (int i = 0; i < m_noOfLabel; i++) {
			m_label[i].printLabel() << endl;
		}
	}
}