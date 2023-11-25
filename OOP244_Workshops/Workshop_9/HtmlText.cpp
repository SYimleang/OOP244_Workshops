/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// HtmlText Module
// File	HtmlText.cpp
// Version 1.0
// Author	Sasawat Yimleang
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Sasawat Yimleang   July 26, 2023        Initialize the HtmlText module for Workshop 9.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "HtmlText.h"

using namespace std;

namespace sdds {

	/* Constructor. Assign the receives parameter values to m_title and m_filename. */
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		if (title != nullptr) {
			
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		else {
			m_title = nullptr;
		}
	}

	/* Destructor.Deallocate the dynamic memory of title attribute. */
	HtmlText::~HtmlText() {
		if (m_title) {
			delete[] m_title;
		}
	}

	/* Constructor. Assign Html */
	HtmlText::HtmlText(const HtmlText& src){
		*this = src;
	}

	/* Overload the assign operator the HtmlText class objects. */
	HtmlText& HtmlText::operator=(const HtmlText& src) {
		if (this != &src) {

			Text::operator=(src);

			if (src.m_title != nullptr) {
				
				(Text&)*this = src;

				m_title = new char[strLen(src.m_title) + 1];
				strCpy(m_title, src.m_title);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

	/* This function override will convert the text file to a simple HTML file. */
	void HtmlText::write(ostream& os)const {

		bool MS = false;

		// Print the title part
		os << "<html><head><title>";
		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}

		// Print the content part.
		for (int ndx = 0; Text::operator[](ndx) != '\0'; ndx++) {
			const char& ch = (*this)[ndx];
			if (ch == ' ') {
				if (MS) {
					os << "&nbsp;";
				}
				else {
					os << ' ';
					MS = true;
				}
			}
			else if (ch == '<'){
				os << "&lt;";
				MS = false;
			}
			else if (ch == '>') {
				os << "&gt;";
				MS = false;
			}
			else if (ch == '\n') {
				os << "<br />\n";
				MS = false;
			}
			else {
				os << ch;
				MS = false;
			}
		}
		os << "</body>\n</html>";
	}
}