/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// HtmlText Module
// File	HtmlText.h
// Version 1.0
// Author	Sasawat Yimleang
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Sasawat Yimleang   July 26, 2023        Initialize the HtmlText header file for Workshop 9.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
#include "cstring.h"

namespace sdds {
   class HtmlText :  public Text {
      char* m_title;    // Holds the title of the HTML conversion dynamically.

   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);  // Constructor with Cstring filename and title with nullptr by default.
      ~HtmlText();                                                          // Destructor.
      HtmlText(const HtmlText& src);                                        // Overload the constructor to copy the HtmlText class objects.
      HtmlText& operator=(const HtmlText& src);                             // Overload the assign operator the HtmlText class objects.

      void write(std::ostream& os)const;    // This override will convert the text file to a simple HTML file.

   };
}
#endif // !SDDS_HTMLTEXT_H__
