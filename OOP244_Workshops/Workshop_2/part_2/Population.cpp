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
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    int noOfPostalCode;
    Population* populate;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPostalCode - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (populate[j].populateNum > populate[j + 1].populateNum) {
                    temp = populate[j];
                    populate[j] = populate[j + 1];
                    populate[j + 1] = temp;
                }
            }
        }
    }

    bool load(struct Population& populates) {
        bool ok = false;
        char ps[128];

        if (read(ps) && read(populates.populateNum)) {
            populates.postal = new char[strLen(ps) + 1];
            strCpy(populates.postal, ps);
            ok = true;
        }
        return ok;
    }

    bool load(const char datafile[]) {
        bool ok = false;
        
        int i;
        if (openFile(datafile)) {
            noOfPostalCode = noOfRecords();
            populate = new Population[noOfPostalCode];
            for (i = 0; i < noOfPostalCode;i++) {
                if (load(populate[i])) {
                    ok = true;
                }
                else {
                    
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                }
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << datafile << endl;
        }
        return ok;
    }

    void display(const Population pop) {
        struct Population population = pop;
        cout << population.postal << ":  " << population.populateNum << endl;
    }

    // TODO: Implementation for the display functions go here
    void display() {
        int totalPop = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfPostalCode; i++) {
            cout << i + 1 << "- ";
            display(populate[i]);
            totalPop += populate[i].populateNum;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPop << endl;
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {

        for (int i = 0; i < noOfPostalCode; i++) {
            delete[] populate[i].postal;
        }
        delete[] populate;
    }
}