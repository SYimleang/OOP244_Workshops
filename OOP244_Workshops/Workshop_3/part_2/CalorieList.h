/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang June 4, 2023    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food* m_food;
        int m_size;
        int m_foodsAdded;
        int totalCalorie()const;
        void Title()const;
        void footer()const;
        bool isValid()const;

    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_CALORIELIST_H