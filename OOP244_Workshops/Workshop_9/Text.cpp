/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Text Module
// File	Text.cpp
// Version 1.0
// Author	Sasawat Yimleang
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Sasawat Yimleang   July 26, 2023        Initialize the Text module for Workshop 9.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <fstream>
#include "Text.h"

using namespace std;

namespace sdds {

    /* Returns the length (size) of the text file on the disk. It returns zero if either the file does not exist or the content is empty. */
   int Text::getFileLength() const {
      int len = 0;
      if (m_filename) {
          ifstream fin(m_filename);
          while (fin) {
              fin.get();
              len += !!fin;
          }
      }
      return len;
   }

   /* This index operator provides read-only access to the content of the text for the derived classes of Text. */
   const char& Text::operator[](int index)const {

       if (index >= 0 || index <= getFileLength()) {

           return m_content[index];
       }
       else {
           return m_content[getFileLength()];
       }
   }

   /* Constructor. Assign the filename of the object to receive value and set content to null. */
   Text::Text(const char* filename) {

       // Check if filename is not same and not empty. Then dynamic allocate the filename and set the filename to receive value.
       if (filename != nullptr && filename[0] != '\0') {
           delete[] m_filename;
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       }
   }

   /* Destructor. Deallocate the dynamic memories of filename and content attributes. */
   Text::~Text() {
       if (m_filename) {
           delete[] m_filename;
       }
       if (m_content) {
           delete[] m_content;
       }
   }

   /* Overload constructor. Copy receive Text class to the object. */
   Text::Text(const Text& src) {
       
       // Check if receives Text class is not empty, then dynamic allocating and set the value to filename.
       if (src.m_filename != nullptr && src.m_filename[0] != '\0') {
           delete[] m_filename;
           m_filename = new char[strLen(src.m_filename) + 1];
           strCpy(m_filename, src.m_filename);
       }
       // If recieves Test class is empty, then set filename to null.
       else {
           m_filename = nullptr;
       }

       // Check if receives Text class is not empty, then dynamic allocating and set the value to content.
       if (src.m_content != nullptr && src.m_content [0] != '\0') {
           delete[] m_content;
           m_content = new char[strLen(src.m_content) + 1];
           strCpy(m_content, src.m_content);
       }
       // If recieves Test class is empty, then set content to null.
       else {
           m_content = nullptr;
       }
   }

   /* Overload the assign operator the Text class objects. */
   Text& Text::operator=(const Text& src) {
       if (this != &src) {

           if (src.m_filename != nullptr && src.m_filename[0] != '\0') {
               delete[] m_filename;
               m_filename = new char[strLen(src.m_filename) + 1];
               strCpy(m_filename, src.m_filename);
           }
           else {
               m_filename = nullptr;
           }

           if (src.m_content != nullptr && src.m_content[0] != '\0') {
               delete[] m_content;
               m_content = new char[strLen(src.m_content) + 1];
               strCpy(m_content, src.m_content);
               
           }
           else {
               m_content = nullptr;
           }
       }
       return *this;
   }

   /* Read the contents of the file character by character into the newly allocated memory */
   void Text::read() {
       
       int fileLen = getFileLength();

       // If file is not empty.
       if (fileLen > 0) {
           // Open file.
           ifstream iFile(m_filename);

           // Read will the current content of the file and then allocates memory to the size of the file on the disk + 1
           delete[] m_content;
           m_content = new char[fileLen + 1];
           iFile.read(m_content, fileLen);

           // Terminates it with a null byte at the end.
           m_content[fileLen] = '\0';

           // Close the file.
           iFile.close();
       }
       // If file is empty, set content to null.
       else {
           m_content = nullptr;
       }
   }

   /* This virtual function will insert the content of the Text class into the ostream if m_content is not null. */
   void Text::write(ostream& os) const {

       // Check that content is not null.
       if(m_content != nullptr) {
           os << m_content;
       }
   }

   /* Overload the insertion operator for a Text object into ostream. */
   ostream& operator<<(ostream& os, const Text& text) {
       text.write(os);
       return os;
   }
}