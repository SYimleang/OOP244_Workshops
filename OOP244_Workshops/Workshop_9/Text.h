/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Text Module
// File	Text.h
// Version 1.0
// Author	Sasawat Yimleang
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Sasawat Yimleang   July 26, 2023        Initialize the Text header file for Workshop 9.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
#include "cstring.h"

namespace sdds {
   class Text {
        char* m_filename { nullptr };   // Hold the name of the file dynamically.
        char* m_content { nullptr };    // Holds the content of the text file dynamically.
        int getFileLength() const;      // Returns the length (size) of the text file on the disk.

   protected:
        const char& operator[](int index) const;     // Overload the operator [] method

   public:
       Text(const char* filename=nullptr);  // Constructor with C-string argument and set default value as nullptr.
       virtual ~Text();                     // Destructor.
       Text(const Text& src);               // Overload the constructor to copy the Text class objects.
       Text& operator=(const Text& src);    // Overload the assign operator the Text class objects.

        void read();                                // Read will the current content of the file.
        virtual void write(std::ostream& os)const;  // Virtual function will insert the content of the Text class into the ostream if m_content is not null.
   };

   std::ostream& operator<<(std::ostream& os, const Text& text);    // Overload the insertion operator for a Text object into ostream.
}
#endif // !SDDS_PERSON_H__

