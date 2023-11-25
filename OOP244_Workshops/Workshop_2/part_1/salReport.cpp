/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang May 23, 2023    create a program that display employees data
/////////////////////////////////////////////////////////////////
***********************************************************************/
//#include "Employee.h"
#include <iostream>
#include "Employee.h"

using namespace std;
using namespace sdds;
int main() {
    // This is Tester section for File.cpp only
    /*
    bool x, y, z;
    char name[100];
    int empNum, numRec;
    double salary;

    openFile("employees.csv");

    x = read(name);
    cout << "The 1st read is: " << x << endl;
    y = read(empNum);
    cout << "The 2nd read is: " << y << endl;
    z = read(salary);
    cout << "The 3rd read is: " << z << endl;
    cout << "The Name is:" << name << ", EmpNum is: " << empNum << ", Salary is: " << salary << endl;

    numRec = noOfRecords();
    cout << "Number of record is: " << numRec << endl;
    closeFile();
    */
    // End of Testing section
    
   if (load()) {
      display();
   }
   deallocateMemory();
   
   return 0;
}