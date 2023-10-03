#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "VideoGameLibrary.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class VideoGame
{
    // Attributes
    Text* title; // pointer to text with game title
    Text* developer; // pointer to text with game developer
    Text* publisher; // pointer to text with game publisher
    int year; // integer containing game release year

    // Functions
    public: 
    VideoGame(Text*, Text*, Text*, int); // Initialize all parameters to videogame object
    ~VideoGame(); // Realse dynamically allocated text arrays in the Video Game
    void printVideoGameDetails(); // Print game details, must call displayText function
    void printVideoGameDetailsToFile(ofstream&); // Put ALL video game info into file. 
    Text* getVideoGameTitle()const; // Accessor, returns pointer with game title
};

#endif 