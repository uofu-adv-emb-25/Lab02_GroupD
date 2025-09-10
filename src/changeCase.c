#include "func.h"

char changeCase(char c) {
    //Changing case of char
    int caseOffset = 32;
    if (c <= 'z' && c >= 'a') 
        c = c - caseOffset;
    else if (c >= 'A' && c <= 'Z') 
        c = c + caseOffset;
    
    return c;
} 