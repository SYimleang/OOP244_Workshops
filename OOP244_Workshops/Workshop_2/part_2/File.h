/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang May 25, 2023    Create DIY Part which modify from WS2 Lab part
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(char* psCode);
   bool read(int& numPop);
}
#endif // !SDDS_FILE_H_
