#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

// Libraries
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Video Game Library Class
class VideoGameLibrary
{
    // Attributes
    public:
    VideoGame** videoGamesArray;
    int maxGames;
    int numGames;

    // Function Prototypes
    public:
    void resizeVideoGameArray(); // Called when adding games to array, and array isnt big enough
    VideoGameLibrary(int); // Constructor, creates new library array
    ~VideoGameLibrary(); // Destructor, prints message stating memory is released
    void addVideoGameToArray(); // Add a single game to array
    void displayVideoGames(); // Print out each video game from library
    void displayVideoGameTitles(); // Print out only game titles from library
    void loadVideoGamesFromFile(char*); // Read from file and put into array
    void removeVideoGameFromArray(); // Remove single video game from their library
    void saveToFile(char*); // Open file and save video game library to it.
};

#endif