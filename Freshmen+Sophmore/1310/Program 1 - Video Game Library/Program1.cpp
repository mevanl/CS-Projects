/*
        NAME:       Mason Lauderdale
        CLASS:      CSC-1310-001
        DUE DATE:   September 14, 2022
*/
#include "VideoGameLibrary.h"
#include "Text.h"
#include "VideoGame.h"

int main()
{
    // Finding size of video game library array
    int arrSize = 0;
    cout << "\n\nHow many video games can your library hold?\n";
    cin >> arrSize;

    // Check if user input was valid
    while((arrSize < 0) || (cin.fail() == true)) // cin.fail will check if the user inputs a non-integer type
    {
        cin.clear(); // Clear bad input if not integer
        cin.ignore();
        cout << "\nInvalid library size! Please Input a new integer.\n";
        cout << "\n\nHow many video games can your library hold?\n";
        cin >> arrSize;
    }
    cin.ignore();

    // Creating Array
    VideoGameLibrary* gameLibrary = new VideoGameLibrary(arrSize);



    // Variables 
    bool endFlag = false; // Flag to end do loop
    int choice = 0; // userInput on menu
    char* loadLibraryPtr;           // char pointer and char for load file 
    char loadLibraryName[1000];
    char* saveLibraryPtr;           // char pointer and char for save file
    char saveLibraryName[1000];

    do 
    {
        cout << "\n\n\tVIDEO GAME LIBRARY MENU" << endl;
        cout << "\n1.\tLoad video games from file.\n";
        cout << "2.\tSave video games to a file.\n";
        cout << "3.\tAdd a video game.\n";
        cout << "4.\tRemove a video game.\n";
        cout << "5.\tDisplay all video games.\n";
        cout << "6.\tRemove ALL video games from this library and end program.\n";
        cout << "CHOOSE 1-6: ";

        cin >> choice; 
        cin.clear();
        cin.ignore();

        while ((choice < 1) || (choice > 6) || (cin.fail() == true)) // making sure user inputs integer between 1 - 6 
        {
            cout << "\nInvalid choice, please reinput." << endl;
            cout << "CHOOSE 1-6: ";
            cin >> choice;
            cin.ignore();
        }
        cin.clear();

        switch(choice)
        {
            case 1:
                cout << "\nWhat is the name of the file of your video game library? (filename.txt format)\n";
                cin >> loadLibraryName;
                cin.ignore();
                
                loadLibraryPtr = loadLibraryName;
                gameLibrary->loadVideoGamesFromFile(loadLibraryPtr);
                break;

            case 2: 
                cout << "\nWhat is the name of the file you want to save your game library too?\n";
                cin >> saveLibraryName;
                cin.ignore();

                saveLibraryPtr = saveLibraryName;
                gameLibrary->saveToFile(saveLibraryPtr);
                break;

            case 3: 
                gameLibrary->addVideoGameToArray();
                break;

            case 4: 
                gameLibrary->removeVideoGameFromArray();
                break;

            case 5: 
                gameLibrary->displayVideoGames();
                break;

            case 6:
                delete gameLibrary;
                endFlag = true; // Do loop will end since true
                break;
        }
    } while (endFlag == false);
    return 0;
}