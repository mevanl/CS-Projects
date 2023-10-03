#ifndef TEXT_H
#define TEXT_H

#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Text
{
    // Attributes
    private:
    char * textArray; // Pointer to an array of characters
    int textLength; // integer of numbers of characters in textArray

    // Functions
    public:
    Text(char*); // Make charater string array from size of string parameter + 1 for null.
    ~Text(); // Release memory for cstring pointing to textArray
    char* getText()const; // Returns textArray
    int getLength()const; // Returns length of the textArray 
    void displayText(); // print textArray

};

#endif