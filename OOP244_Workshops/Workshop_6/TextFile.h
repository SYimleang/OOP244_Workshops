/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// TextFile Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang Jul 05, 2023    Create the reading and copy file data program
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {

    //Initialize prefix of copy file name
    const char cpyPrefix[3] = "C_";

   class Line {
      char* m_value{ nullptr }; // Initial as nullptr
      operator const char* ()const; 
      Line() {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;
   public:
      // copy and copy assignment prevention goes here
       Line(const Line& line) = delete;
       Line& operator=(const Line& line) = delete;
   };

   class TextFile {
       Line* m_textLines{ nullptr }; //Initial as nullptr
       char* m_filename { nullptr }; //Initial as nullptr
      unsigned m_noOfLines;
      unsigned m_pageSize;
      void setFilename(const char* fname, bool isCopy = false); //Default is not copy
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15); //Default is 15 pages
      TextFile(const TextFile& textFile);
      TextFile& operator=(const TextFile& textFile);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__
