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

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char foodName[31];
        int foodCalorie;
        int consumpTime;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorie, int time);
        void display()const;
        bool isValid()const;
        int calorie()const;
    };
}

#endif // !SDDS_FOOD_H