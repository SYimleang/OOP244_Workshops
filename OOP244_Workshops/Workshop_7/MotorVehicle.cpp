/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// MotorVehicle module
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang July 12, 2023   Initialize MotorVehicle module.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	//Default constructor.
	MotorVehicle::MotorVehicle() {
		m_licensePlate[0] = '\0';
		m_address[0] = '\0';
		m_year = 0;
	}

	/*Constructor.Receives as parameters the license plate numberand the year when the vehicle was built.*/
	MotorVehicle::MotorVehicle(const char* licensePlate, int year) {

		//Copy receives parameter to members.
		m_year = year;
		strnCpy(m_licensePlate, licensePlate, 8);
		m_licensePlate[8] = '\0';

		//Set address to "Factory"
		strCpy(m_address, "Factory");
	}

	//Destructor.
	MotorVehicle::~MotorVehicle() {

	}

	/*moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message.*/
	void MotorVehicle::moveTo(const char* address) {

		//Check if addresses are valid.
		if (strCmp(m_address, address) != 0) {
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_licensePlate << "| |";
			cout.width(20);
			cout << m_address;
			cout << " ---> ";
			cout.unsetf(ios::right);
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout << "|" << endl;
			cout.unsetf(ios::left);
			strCpy(m_address, address);
		}

	}

	/*A query that inserts into os the content of the object in the format.*/
	ostream& MotorVehicle::write(ostream& os) const{
		os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;
		return os;
	}

	/*A mutator that reads from the stream in the data for the current object.*/
	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_licensePlate;
		cout << "Current location: ";
		in.ignore();
		in.getline(m_address, 64);

		return in;
	}

	/*Overload extraction operator to print content from write() function.*/
	ostream& operator<<(ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}

	/*Overload insertion operator to get content from read() function.*/
	istream& operator>>(istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}

}