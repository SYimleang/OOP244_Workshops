/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Version 1.0
// Description
// Marks calculator program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 15, 2023	Create the marks transformation program
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {

	// Constructor. Set value of marks to 0
	Mark::Mark() {
		m_marks = 0;
	}

	// Constructor with one parameter
	Mark::Mark(int marks) {

		// If received value is between 0 to 100, then assign received value to marks.
		if (marks >= 0 && marks <= 100) {
			m_marks = marks;
		}

		// Otherwise, assign marks to -1 (Empty state)
		else {
			m_marks = -1;
		}
	}

	// Overload integer type of variables
	Mark::operator int() const {
		int results = 0;

		// If the value is valid, return the value. Otherwise, return zero
		if (m_marks >= 0 && m_marks <= 100) {
			results = m_marks;
		}
		return results;
	}

	// Overload double type of variables. Return GPA follow marks value, as 4.0, 3.0, 2.0, 1.0 and 0.0. Otherwise, return 0.0
	Mark::operator double() const {
		double gpa = 0.0;

		// If marks is be between 80 to 100, then assign GPA to 4.0
		if (m_marks >= 80 && m_marks <= 100) {
			gpa = 4.0;
		}

		// If marks is be between 70 to 79, then assign GPA to 3.0
		else if (m_marks >= 70 && m_marks < 80) {
			gpa = 3.0;
		}

		// If marks is be between 60 to 69, then assign GPA to 2.0
		else if (m_marks >= 60 && m_marks < 70) {
			gpa = 2.0;
		}

		// If marks is be between 50 to 59, then assign GPA to 1.0
		else if (m_marks >= 50 && m_marks < 60) {
			gpa = 1.0;
		}

		// Otherwise, assign GPA to 0.0
		else if (m_marks >= 0 && m_marks < 50) {
			gpa = 0.0;
		}
		return gpa;
	}

	// Overload character type of variables. Return Grade character follow marks value, as A, B, C, D and F. Otherwise, Return character X
	Mark::operator char() const {
		char grade = 'X';

		// If marks is be between 80 to 100, then assign Grade to A
		if (m_marks >= 80 && m_marks <= 100) {
			grade = 'A';
		}

		// If marks is be between 70 to 79, then assign Grade to B
		else if (m_marks >= 70 && m_marks < 80) {
			grade = 'B';
		}

		// If marks is be between 60 to 69, then assign Grade to C
		else if (m_marks >= 60 && m_marks < 70) {
			grade = 'C';
		}

		// If marks is be between 50 to 59, then assign Grade to D
		else if (m_marks >= 50 && m_marks < 60) {
			grade = 'D';
		}

		// If marks is be between 0 to 50, then assign Grade to F
		else if (m_marks >= 0 && m_marks < 50) {
			grade = 'F';
		}
		
		return grade;
	}

	// Overload += operator.
	Mark& Mark::operator+=(const int value) {

		// If marks plus value is less than 100, then assign marks to 0
		if (m_marks + value >= 100) {
			m_marks = -1;
		}

		// If marks is valid, then add value to marks
		else if (m_marks >= 0 && value >= 0) {
			m_marks += value;
		}
		
		return *this;
	}

	// Overload = operator. 
	Mark& Mark::operator=(const int value) {

		// If received value is between 0 to 100, then assign marks to received value.
		if (value >= 0 && value <= 100) {
			m_marks = value;
		}

		// If value is invalid, then assign marks to 0.
		else if (value < 0 || value > 100) {
			m_marks = -1;
		}

		return *this;
	}

	// Overload += helper operator. Return the integer of marks.
	int operator+=(int& value, Mark& marks) {

		// If marks is valid, then add value by integer of marks.
		if ((int)marks >= 0 && (int)marks <= 100) {
			value += (int)marks;
		}
		return value;
	}

}

