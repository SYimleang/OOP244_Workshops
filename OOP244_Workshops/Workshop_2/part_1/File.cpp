#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // TODO: read functions go here    
    bool read(char* arr) {
        bool flag = false;
        if (fscanf(fptr, "%[^\n]\n", arr)) {
            flag = true;
        }
        return flag;
    }

    bool read(int& employeeNum) {
        bool flag = false;
        if (fscanf(fptr, "%d,", &employeeNum)) {
            flag = true;
        }
        return flag;
    }
    bool read(double& salary) {
        bool flag = false;
        if (fscanf(fptr, "%lf,", &salary)) {
            flag = true;
        }
        return flag;
    }
}