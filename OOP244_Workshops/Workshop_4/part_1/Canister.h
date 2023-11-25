/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// Canister Header file
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 7, 2023    Create the Canister calculation program
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
   class Canister {
      char* m_contentName;      // points to a dynamically allocated Cstring.
      double m_diameter;        // in centimeters 
      double m_height;          // in centimeters
      double m_contentVolume;   // in CCs
      bool m_usable;            // a flag to identify if the Canister is usable or unusable
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
   public:
       void clear();
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter, const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      
   };
}

#endif // !SDDS_BOX_H
