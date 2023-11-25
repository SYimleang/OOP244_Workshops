/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// Truck module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 12, 2023	Initialize Truck module which is part of MotorVehicle module.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Truck.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	/*Default Constructor*/
	Truck::Truck() : MotorVehicle("", 0){
		m_capacity = 0;
		m_cargo = 0;
	}

	/*Constructor. Receives as parameters the license plate number, 
	the year when the truck was built, the capacity of the truck and the current address.*/
	Truck::Truck(const char* license, int year, double capacity, const char* address):MotorVehicle(license, year) {
		MotorVehicle::moveTo(address);
		m_capacity = capacity;
		m_cargo = 0;
	}

	/*Destructor.*/
	Truck::~Truck() {

	}

	/*A mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter.*/
	bool Truck::addCargo(double cargo) {

		bool status = false;

		//If after add recieved cargo to current cargo and not exceed the capacity.
		if ((m_cargo + cargo) <= m_capacity) {
			m_cargo += cargo;					//Add recieved cargo to current cargo
			status = true;						// Sets status to true.
		}
		else if (m_cargo < m_capacity) {
			m_cargo = m_capacity;
			status = true;
		}

		return status;
	}

	/*A mutator that unloads current cargo (sets the attribute to 0).*/
	bool Truck::unloadCargo() {

		bool status = false;

		//If current cargo is valid, then set current cargo to zero.
		if (m_cargo > 0) {
			m_cargo = 0;
			status = true;						//Sets status to true.
		}

		return status;
	}

	/*A query that inserts into os the content of the object in the format.*/
	ostream& Truck::write(ostream& os) const {

		//Call funtion write() from MotorVehicle class.
		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;

		return os;
	}

	/*A mutator that reads from the stream in the data for the current object.*/
	istream& Truck::read(istream& in) {

		//Call function read() from MotorVehicle class.
		MotorVehicle::read(in);

		//Get input of capacity and cargo from user.
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;

		return in;
	}

	/*Overload extraction operator to print content from write() function in the Truck class.*/
	ostream& operator<<(ostream& os, const Truck& truck) {
		return truck.write(os);
	}

	/*Overload insertion operator to get content from read() function in the Truck class.*/
	istream& operator>>(istream& in, Truck& truck) {
		return truck.read(in);
	}
}