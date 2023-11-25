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

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Label.h"

using namespace std;
namespace sdds {

	// Constructor
	Label::Label() {

		// Sets class members to default values
		setToDefault();

		// Sets frame as format and label content to nullptr
		setLabel("+-+|+-+|");
		
	}

	// Constructor with one argument
	Label::Label(const char* frameArg) {

		// Sets class members to default values
		setToDefault();
		
		// Sets frame as received parameter and label content to nullptr
		setLabel(frameArg);		
	}

	// Constructor with two arguments
	Label::Label(const char* frameArg, const char* content) {

		// Sets class members to default values
		setToDefault();

		// Assign the label content and frame to received argument
		setLabel(frameArg, content);
		
	}

	// Destructor
	Label::~Label() {
		delete[] m_content;
		delete[] m_frame;
	}

	// Reset to label content and frame to nullptr (default values).
	void Label::setToDefault() {
		m_content = nullptr;
		m_frame = nullptr;
	}

	void Label::setLabel(const char* frameArg, const char* content) {

		
		// If received content parameter is null ptr, then sets m_content to nullptr
		if (content == nullptr){
			m_content = nullptr;
		}
		// Otherwis, Dynamic allocating m_content, then sets m_content to received parameter(content)
		else {
			m_content = new char[strLen(content) + 1];
			strCpy(m_content, content);
			m_content[strLen(m_content)] = '\0';
		}
		// If frameArg is not nullptr, then dynamic allocating m_frame and sets m_frame to received parameter(frameArg).
		if (frameArg != nullptr) {
			m_frame = new char[strLen(frameArg) + 1];
			strCpy(m_frame, frameArg);
			m_frame[strLen(m_frame)] = '\0';
		}
	}

	// Read label of cin from main function (which use cin)
	void Label::readLabel() {
		char content[71];
		cout << "> ";
		cin.getline(content, 71);

		// Sets label as received value from cin
		setLabel(m_content, content);
	}

	// print label in formatted
	std::ostream& Label::printLabel()const {
		
		// Check if m_content is not nullptr, then print label. Otherwise print nothing.
		if (m_content != nullptr) {
			int frameLen = strLen(m_content) + 3;

			// print first line of the label (top of the label)
			cout << m_frame[0];
			cout.width(frameLen);
			cout.fill(m_frame[1]);
			cout << m_frame[2] << endl;

			// print second line of the label
			cout << m_frame[3];
			cout.width(frameLen);
			cout.fill(' ');
			cout << m_frame[3] << endl;

			// print third line of the label (label name)
			cout << m_frame[3] << ' ' << m_content << ' ' << m_frame[3] << endl;

			// print fourth line of the label
			cout << m_frame[3];
			cout.width(frameLen);
			cout.fill(' ');
			cout << m_frame[3] << endl;

			// print fifth line of the label (bottom of the label)
			cout << m_frame[6];
			cout.width(frameLen);
			cout.fill(m_frame[5]);
			cout << m_frame[4];
		}
		return cout;
	}
	
}