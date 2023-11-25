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
#include "Population.h"
using namespace sdds;
int main() {
    if (load("PCpopulations.csv")){
      display();
   }
   deallocateMemory();
   return 0;
}