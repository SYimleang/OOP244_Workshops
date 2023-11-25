/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// Truck Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 12, 2023	Initialize header file of Truck module
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__

#define SIZE_OF_LICENSE 9
#define SIZE_OF_ADDRESS 64

#include <iostream>
#include "MotorVehicle.h"

using namespace std;

namespace sdds {

	class Truck : public MotorVehicle{	//Inherits MotorVehicle class
		double m_capacity;				//Max capacity of current truck
		double m_cargo;					//Current load of the truck

	public:
		Truck();																	//Default constructor
		Truck(const char* license, int year, double capacity, const char* address);	//Constructor
		~Truck();																	//Destructor

		bool addCargo(double cargo);		//Add load to the cargo
		bool unloadCargo();					//Unload the load from current cargo
		ostream& write(ostream& os) const;	//Print output in format
		istream& read(istream& in);			//Get input from user
	};

	ostream& operator<<(ostream& os, const Truck& truck);	//Overload Extraction operator
	istream& operator>>(istream& in, Truck& truck);			//Overload Insertion operator
}
#endif