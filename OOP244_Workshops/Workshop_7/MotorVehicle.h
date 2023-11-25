/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// MotorVehicle Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 12, 2023   Initialize header file of MotorVehicle module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__

#include <iostream>
using namespace std;
namespace sdds {

	class MotorVehicle {
		char m_licensePlate[9];						//array of characters to hold the license plate number
		char m_address[64];							//Array of characters to hold the current address
		int m_year;									//Number of production year

	public:
		MotorVehicle();								//Default constructor
		MotorVehicle(const char* licensePlate, int year);	//Constructor
		~MotorVehicle();							//Destructor

		void moveTo(const char* address);			//Moves vehicle to the address
		ostream& write(ostream& os) const;			//Print output in format
		istream& read(istream& in);					//Get input from user
	};

	ostream& operator<<(ostream& os, const MotorVehicle& vehicle);	//Overload Extraction operator
	istream& operator>>(istream& in, MotorVehicle& vehicle);		//Overload Insertion operator

}
#endif
