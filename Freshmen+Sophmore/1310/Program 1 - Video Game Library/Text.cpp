#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Construtor, takes in pointer to cstring, copies and assigns it to textArray
Text::Text(char* arr)
{
    textLength = (strlen(arr)); // Get Length

    char* temp = new char[textLength+1]; // Length+1 for null, dynamically allocated 

    temp = strcpy(temp, arr); // Copy cstring, pass it to textArray
    textArray = temp;
}

// Accessor that returns textArray
char* Text::getText()const
{
    return textArray;
}

// Accessor that returns textLength
int Text::getLength()const
{
    return textLength;
}

// Prints text to screen
void Text::displayText()
{
    cout << textArray;
}

// Destructor, releases textArray
Text::~Text()
{
    delete textArray;
    cout << "\nText destructor: Released memory for textArray.";
}

