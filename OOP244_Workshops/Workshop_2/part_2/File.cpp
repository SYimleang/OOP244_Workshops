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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* psCode) {
       bool flag = false;
       if (fscanf(fptr, "%3[^,],", psCode)) {
               flag = true;
       }
       return flag;
   }
   bool read(int& numPop) {
       bool flag = false;
       if (fscanf(fptr, "%d\n", &numPop)) {
           flag = true;
       }
       return flag;
   }
}