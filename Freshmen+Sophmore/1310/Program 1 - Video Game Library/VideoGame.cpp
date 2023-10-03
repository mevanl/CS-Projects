#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

// Constructor that initialized the variables passed to it
VideoGame::VideoGame(Text* gameTitle, Text* gameDev, Text* gamePub, int gameYear)
{
    title = gameTitle;
    developer = gameDev;
    publisher = gamePub;
    year = gameYear;
}

// Print details for just one game
void VideoGame::printVideoGameDetails()
{
    cout << "\n\t\t" << setw(17) <<"GAME NAME: ";
    title->displayText(); 

    cout << "\n\t\t" << setw(17) << "GAME DEVELOPER: ";
    developer->displayText();

    cout << "\n\t\t" << setw(17) << "GAME PUBLISHER: ";
    publisher->displayText();

    cout << "\n\t\t" << setw(17) << "RELEASE YEAR: " << year;
}

// Print a game's details to a file
void VideoGame::printVideoGameDetailsToFile(ofstream &outFile)
{
    outFile << title->getText() << "\n";
    outFile << developer->getText() << "\n";
    outFile << publisher->getText() << "\n";
    outFile << year << "\n";
}

// Accessor for game title
Text* VideoGame::getVideoGameTitle()const
{
    return title;
}

// Destructor that releases dynamically allocated information
VideoGame::~VideoGame()
{
    delete title;
    delete developer;
    delete publisher;
    cout << "VideoGame destructor: Released memory for VideoGame object.\n";
}