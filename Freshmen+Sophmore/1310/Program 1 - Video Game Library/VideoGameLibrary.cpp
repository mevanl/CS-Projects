#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Constructor that dynamically allocates array of pointer to Video game objects, initializes variables 
VideoGameLibrary::VideoGameLibrary(int arrSize)
{
    maxGames = arrSize;
    numGames = 0; // Initialize number of games in new array to zero

    videoGamesArray = new VideoGame*[maxGames];
}

// Double the array if it fills up and user wants more. 
void VideoGameLibrary::resizeVideoGameArray()
{
    maxGames = (maxGames*2);
    VideoGame** tempArray = new VideoGame*[maxGames]; // make a temporary array, with double size

    // Loop through each element and put into new array
    for(int i = 0; i<numGames; i++)
    {
        tempArray[i] = videoGamesArray[i];
    }
    
    // Update new maxGames size, assign videoGamesArray to the temp array
    videoGamesArray = tempArray;

}

// Add single game to library
void VideoGameLibrary::addVideoGameToArray()
{
    // GAME TITLE

    char * titlePtr;
    char gameTitle[10000];
    // Get game title from user
    cout << "\nEnter the video game title: ";
    cin.getline(gameTitle, 10000);
    cin.clear();
    titlePtr = gameTitle;
    // Converting game title to text obect
    Text * title = new Text(titlePtr);

    // GAME DEVELOPER

    char * devPtr;
    char gameDev[10000];
    // Get game developer from user
    cout << "\nEnter the video game's developer: ";
    cin.getline(gameDev, 10000);
    cin.clear();
    devPtr = gameDev;
    // Converting game dev to text object
    Text * developer = new Text(devPtr);

    // GAME PUBLISHER

    char * pubPtr;
    char gamePublisher[10000];
    // Get game publisher from user
    cout <<"\nEnter video game's publisher: ";
    cin.getline(gamePublisher, 10000);
    cin.clear();
    pubPtr = gamePublisher;
    // Converting game publisher to text object; 
    Text * publisher = new Text(pubPtr);

    // GAME RELEASE YEAR

    int releaseYear = -1; // default value
    // Get release year from user
    cout << "\nEnter video game's release year: ";
    cin >> releaseYear;
    cin.clear();

    // VIDEO GAME OBJECT CREATION
    VideoGame* newGame = new VideoGame(title, developer, publisher, releaseYear); // new video game object

    // CHECK IF ARRAY IS FULL OR NOT
    if (numGames == maxGames)
    {
        resizeVideoGameArray();
    }

    // ASSIGN GAME OBJECT TO ARRAY, AND INCREMENT
    videoGamesArray[numGames] = newGame;
    numGames++;
}

// Print out each video game from library
void VideoGameLibrary::displayVideoGames()
{
    for(int i = 0; i < numGames; i++)
    {
        cout << "\n\tVIDEO GAME " << i + 1 << ":" << endl;
        videoGamesArray[i]->printVideoGameDetails();
        cout << "\n";
    }
}

// Print out each video game title from library
void VideoGameLibrary::displayVideoGameTitles()
{
    cout << "Video Game Titles:\n";
    for (int i = 0; i<numGames; i++)
    {
        cout << "\n" << i+1 << ". ";
        videoGamesArray[i]->getVideoGameTitle()->displayText();
        cout << "\n";
    }
}   

// Take in preformatted file, read and place information into video game object and into library
void VideoGameLibrary::loadVideoGamesFromFile(char* filename)
{
    ifstream gameLibrary; 

    // Making sure the file actually opened
    gameLibrary.open(filename);
    while (gameLibrary.is_open() == false)
    {
        cout << "\n\nFile failed to open! Please enter a valid file and file name! (filename.txt)" << endl;
        cin >> filename;
        cin.clear();
    } 

    gameLibrary.clear();
    int runningTotal = 0; // Total # of games added at end

        char* titlePtr;
        char* devPtr;
        char* pubPtr;
        char tempTitle[10000];
        char tempDev[10000];
        char tempPub[10000];
        int tempYear = -1;

    // Going through file
    while(!gameLibrary.eof()) // Read entire file
    {
        // Title
        gameLibrary.getline(tempTitle, 10000, '\n');
        titlePtr = tempTitle;

        Text* gameTitle = new Text(titlePtr);

        // Dev
        gameLibrary.getline(tempDev, 10000, '\n');
        devPtr = tempDev;

        Text* gameDev = new Text(devPtr);

        // Pub
        gameLibrary.getline(tempPub, 10000, '\n');
        pubPtr = tempPub;

        Text* gamePub = new Text(pubPtr);

        // Year
        gameLibrary >> tempYear;
        gameLibrary.ignore();


        // Create new video game object
        VideoGame* newGame = new VideoGame(gameTitle, gameDev, gamePub, tempYear); 

        // Resize incase fill
        if (numGames == maxGames)
        {
            resizeVideoGameArray();
        }

        videoGamesArray[numGames] = newGame;
        numGames++;

        cout << "\n"; 
        videoGamesArray[numGames-1]->getVideoGameTitle()->displayText(); // Display title everytime game was added
        cout << " was successfully added to the library." << endl;
        runningTotal++;
    }
    cout << "\n" << runningTotal << " new games were added to the library." << endl;
}

void VideoGameLibrary::removeVideoGameFromArray()
{
    int userChoice = 0;

    // Error Checking
    if (numGames == 0)
    {
        cout << "\nSorry! There must be atleast one game in the library to do this action!" << endl;
        return;
    }

    displayVideoGameTitles(); // Show user the game list, so they know the number for deletion 

    cout << "\n\nEnter a title number (1 - " << numGames << ") from your library you wish to delete: ";
    cin >> userChoice;
    cin.ignore();

    // Making sure the title # is valid
    if ((userChoice < 0) || (userChoice > numGames))
    {
        cout << "\nInvalid Input! Select a title number (1 - " << numGames << "): " << endl;
        cin >> userChoice;
        cin.ignore();
    }

    (videoGamesArray[userChoice-1]->getVideoGameTitle())->displayText();
    cout << " has successfully been removed from the video game library." << endl;

    // Release video game from array
    delete videoGamesArray[userChoice-1];
    int emptyIndex = userChoice-1; // this is the index of the game the user wants gone. 

    // Shift all elements of the array to the left
    for(int i = userChoice; i < numGames; i++)
    {
        videoGamesArray[emptyIndex] = videoGamesArray[i];
        emptyIndex++;
    }
    numGames--;
}

// Take in file, print out game information in correct format
void VideoGameLibrary::saveToFile(char* filename)
{
    ofstream outputFile;

    outputFile.open(filename, ios::out);

    // Check if file exist
    if(!outputFile)
    {
        cout << "Could not open file.\n";
    }

    for(int i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->printVideoGameDetailsToFile(outputFile);
    }

    outputFile.close();
    cout << "\nSuccessfully printed video game library to " << filename << ".\n";
}

// Destructor, sends message when deletion was successful 
VideoGameLibrary::~VideoGameLibrary()
{
    for(int i = 0; i < numGames; i++)
    {
        delete videoGamesArray[i];
    }

    delete [] videoGamesArray;

    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.\n";
}