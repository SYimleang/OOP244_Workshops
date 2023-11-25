/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name             Date            Reason
// Sasawat Yimleang August 1, 2023  Initialize searchNlist module file.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include <string.h>
#include "Collection.h"

using namespace std;

namespace sdds {

    /* Function to display all the element inside passed parameter, with the title of the string. */
    template <typename T>
    void listArrayElements(const char* title, const T* arr, int size) {
        cout << title << endl;

        // Loop through all element of received arr parameter
        for (int i = 0; i < size; i++) {

            // Checks if the element of arr pamameter has a content, then print the index and its content.
            if (&arr[i]) {
                cout << i + 1 << ": " << arr[i] << endl;
            }
        }
    }

    /* Funvtion to search the matching content of recieved T2 array type and the key T3 to find. and collect result into T1 array. */
    template <typename T1, typename T2, typename T3>
    bool search(Collection<T1>& collect, const T2 arr[], int size, const T3& key) {
        bool found = false;

        // Clear the Collection before performing the search.
        collect.resize(0);
        
        // Loop to checks all the match element.
        for (int i = 0; i < size; i++) {

            // If element is matches, then add this element to collection array.
            if (arr[i] == key) {
                collect.add(arr[i]);
                found = true;
            }
        }

        return found;
    }
}
#endif