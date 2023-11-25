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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Population {
		char* postal;
		int populateNum;
	};

	void sort();
	bool load(const char datafile[]);
	void display(const Population pop);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_