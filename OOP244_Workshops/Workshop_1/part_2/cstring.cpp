namespace sdds {
    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src) {
        int ndx = 0;
        while(src[ndx]!='\0'){
            des[ndx] = src[ndx];
            ndx++;
        }
        des[ndx] = '\0';
    }

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len) {
        int ndx;
        for (ndx = 0; ndx < len; ndx++) {
            des[ndx] = src[ndx];
        }
    }

    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2) {
        int ndx = 0;
        while (s1[ndx] != '\0'){
            if (( s1[ndx] > s2[ndx] ) || ( s1[ndx] < s2[ndx] )) {
                return s1[ndx] - s2[ndx];
            }
            ndx++;
        }
        return 0;
    }

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len) {
        int ndx;
        for (ndx = 0; ndx < len; ndx++) {
            if ((s1[ndx] > s2[ndx]) || (s1[ndx] < s2[ndx])) {
                return s1[ndx] - s2[ndx];
            }
        }
        return 0;
    }

    // returns the lenght of the C-string in characters
    int strLen(const char* s) {
        int len = 0;
        while (s[len]) {
            len++;
        }
        return len;
    }

    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2) {
        int ndx1 = 0, ndx2 = 0;
        if (str1 == nullptr || str2 == nullptr ) {  // Validate str1 and str2 are not NULL
            return nullptr;
        }
        while (str1[ndx1]) {
            if (str2[ndx2] == '\0') {
                return &str1[ndx1 - ndx2];
            }
            if (str1[ndx1] == str2[ndx2]) {         // Increase index of str2 if the element is matching
                ndx2 += 1;
            }
            else {                                  // Reset index of str2 if the element not matching
                ndx2 = 0;
            }
            ndx1++;
        }
        return nullptr;
    }

    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) {
        int ndx1 = 0, ndx2 = 0;
        while (des[ndx1] != '\0') {
            ndx1++;
        }
        while (src[ndx2]) {
            des[ndx1] = src[ndx2];
            ndx1++;
            ndx2++;
        }
        des[ndx1] = '\0';
    }
}