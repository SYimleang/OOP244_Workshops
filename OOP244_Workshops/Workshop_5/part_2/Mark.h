/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Version 1.0
// Description
// marks calculator header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 15, 2023	Create the marks transformation program
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
	class Mark {
		int m_marks;
	public:
		Mark();
		Mark(int marks);
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator=(const int value);
		Mark& operator+=(const int value);
	};
	int operator+=(int& value, Mark& marks);
}


#endif // SDDS_MARK_H_
