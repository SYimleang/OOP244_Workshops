/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// TextFile module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang Jul 05, 2023    Create the reading and copy file data program
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {

   // Line Class Methods
   Line::operator const char* () const {
      return (const char*)m_value;
   }

   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }

   Line::~Line() {
      delete[] m_value;
   }


   // TextFile Class Methods

   /*If the isCopy argument is false, dynamically allocates a Cstring in m_filename 
   and copies the content of the fname argument into it. If the isCopy argument is true, 
   dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.*/
   void TextFile::setFilename(const char* fname, bool isCopy) {

       //If not for copy, copy with the same name
       if (isCopy == false) {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
       }

       //If for copy, copy by start with "C_" then file name
       else {
           m_filename = new char[strLen(fname) + strLen(cpyPrefix) + 1];
           strCpy(m_filename, cpyPrefix);
           strCat(m_filename, fname);
       }
   }

   // Counts the number of lines in the file.
   void TextFile::setNoOfLines() {

       // Creates a local ifstream object to open the file with the name held in m_filename.
       ifstream iFile(m_filename);
       char fChar;

       //Check if the file is open
       if (iFile.is_open()) {

           // Read the file, character by character, and increase number of lines when found new line character.
           while (iFile) {
               iFile.get(fChar);
               if (fChar == '\n') {
                   m_noOfLines++;
               }
           }
           // In case last character is not new line character, increase number of line by one.
           m_noOfLines++;

           // Close the file.
           iFile.close();
       }

       // If number of line is zero, then set everything to empty state.
       else{
           setEmpty();
       }
   }

   // Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines.
   void TextFile::loadText() {

       //If filename is not nullptr, then set to nullptr
       if (m_filename != nullptr) {

           //If text in line is not nullptr, then set to nullptr
           if (m_textLines != nullptr) {
               setEmpty();
           }

           // Dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
           m_textLines = new Line[m_noOfLines];
           string lines;
           unsigned counter = 0;

           // Creates a local ifstream object to open the file with the name held in m_filename.
           ifstream iFile(m_filename);
           
           //If file is opening
           if (iFile.is_open()) {

               //Loop thought all lines
               while (getline(iFile, lines)) {

                   //Dynamic allocate each text line, then set to data from file
                   m_textLines[counter].m_value = new char[strLen(lines.c_str()) +1];
                   strCpy(m_textLines[counter].m_value, lines.c_str());
                   counter++;
               }
               iFile.close();
           }

           //Set number of line to line counter.
           m_noOfLines = counter;
       }

   }

   // Saves the content of the TextFile under a new file.
   void TextFile::saveAs(const char* fileName)const {

       //Open the file
       ofstream oFile(fileName);
       
       //Loop throught all the line for saves the text line by line
       for (unsigned ndx = 0; ndx < m_noOfLines; ndx++) {
           oFile << m_textLines[ndx] << endl;
       }

       //Close the file
       oFile.close();
   }

   /*deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring 
   and sets is to nullptr sets m_noOfLines attribute to zero.*/
   void TextFile::setEmpty() {

       //If text line is not nullptr, then set to nullptr
       if (m_textLines != nullptr) {
           delete[] m_textLines;
           m_textLines = nullptr;
       }

       //If file name is not nullptr, then set to nullptr
       if (m_filename != nullptr) {
           delete[] m_filename;
           m_filename = nullptr;
       }

       //Set number of line to 0
       m_noOfLines = 0;
   }

   // Constructor
   TextFile::TextFile(unsigned pageSize) {
       setEmpty();

       // Initializes the m_pageSize attribute using the pageSize argument.
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
       setEmpty();

       // Initializes the m_pageSize attribute using the pageSize argument.
       m_pageSize = pageSize;

       // If the filename is not null, it will set the filename, set the number of Lines and load the Text.
       if (filename != nullptr && filename[0] != '\0') {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }

   // Copy Constructor
   TextFile::TextFile(const TextFile& textFile) {
       
       setEmpty();

       // Initializes the m_pageSize attribute using the pageSize of the TextFile class argument.
       m_pageSize = textFile.m_pageSize;

       // If TextFile is valid, copies the file to current object.
       if (this != &textFile) {
           if (textFile.m_textLines && textFile.m_noOfLines > 0) {

               //Set file name as a copy and set number of line
               setFilename(textFile.m_filename, true);
               m_noOfLines = textFile.m_noOfLines;

               //Dynamic allocate the textline
               m_textLines = new Line[m_noOfLines];

               unsigned ndx = 0;

               //Loop throught all line and copy textline to the copied file
               while (ndx < m_noOfLines) {
                   m_textLines[ndx].m_value = new char[strLen(textFile.m_textLines[ndx].m_value) + 1];
                   strCpy(m_textLines[ndx].m_value, textFile.m_textLines[ndx].m_value);
                   ndx++;
               }

               //Save copied data as new file
               saveAs(m_filename);
           }
       }
       
   }

   // Copy Assignments
   TextFile& TextFile::operator=(const TextFile& textFile) {

       // If TextFiles are valid, it will delete the current text and overwrites the current file.
       if (this != &textFile) {
           if (m_textLines != nullptr) {
               delete[] m_textLines;
               m_textLines = nullptr;
           }

           // If text lines are Valid, then saves the text into current file
           if (textFile.m_textLines && textFile.m_noOfLines > 0) {
               this->m_noOfLines = textFile.m_noOfLines;
               m_textLines = new Line[m_noOfLines];

               unsigned ndx = 0;
               while (ndx < m_noOfLines) {
                   m_textLines[ndx].m_value = new char[strLen(textFile.m_textLines[ndx].m_value) + 1];
                   strCpy(m_textLines[ndx].m_value, textFile.m_textLines[ndx].m_value);
                   ndx++;
               }
               saveAs(m_filename);
           }
       }
       return *this;
   }

   // Destructor
   TextFile::~TextFile() {
       setEmpty();
   }

   // Returns true if the TextFile is not in an empty state and returns false if it is.
   TextFile::operator bool()const {
       bool fileStatus = false;
       if (this->m_filename != nullptr) {
           fileStatus = true;
       }
       return fileStatus;
   }

   // Return number of line.
   unsigned TextFile::lines()const {
       return m_noOfLines;
   }

   // Return file name
   const char* TextFile::name()const {
       return m_filename;
   }

   // Prints the filename and then the content of the file "m_pageSize" lines at a time.
   std::ostream& TextFile::view(std::ostream& ostr)const {
       
       //If filename is Valid, then print as a format
       if (m_filename != nullptr && m_filename[0] != '\0') {
           ostr << m_filename << endl;

           ostr.fill('=');
           ostr.width(strLen(m_filename));
           ostr << '=' << endl;

           unsigned ndx = 0;

           // loops through the lines and print them one by line
           while (ndx < m_noOfLines && ndx < m_pageSize) {
               ostr << m_textLines[ndx] << endl;
               ndx++;
           }

           if (ndx < m_noOfLines) {
               do {
                   ostr << "Hit ENTER to continue...";
                   char x;
                   cin.get(x);

                   for (unsigned ndx2 = 0; ndx2 < m_pageSize && ndx < m_noOfLines; ndx2++) {
                       ostr << m_textLines[ndx] << endl;
                       ndx++;
                   }
               } while (ndx < m_noOfLines);
           }
       }

       return ostr;
   }

   // Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text. When done it will return the istr;
   std::istream& TextFile::getFile(std::istream& istr) {

       string iText;
       istr >> iText;

       //Dynamic allocate the file name, and copy the file name
       m_filename = new char[strLen(iText.c_str()) + 1];
       strCpy(m_filename, iText.c_str());

       //Clear buffer of input stream
       istr.ignore(32767, '\n');

       //Set number of line and load textline
       setNoOfLines();
       loadText();

       return istr;
   }

   //Overload operator []
   const char* TextFile::operator[](unsigned index)const{
       if (m_filename != nullptr && m_filename[0] != '\0') {
           if (index >= m_noOfLines) {
               index -= m_noOfLines;
           }
       }

       return m_textLines[index].m_value;
   }

   //Overload helper operator << for print the output
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       text.view(ostr);
       return ostr;
   }

   //Overload helper operator >> for get file data
   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       text.getFile(istr);
       return istr;
   }
}
  