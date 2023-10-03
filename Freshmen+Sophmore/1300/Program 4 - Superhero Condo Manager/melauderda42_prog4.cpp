/*******************************************************************
	Title: 		melauderda42_prog4.cpp
	Author: 	Mason Lauderdale, melauderda42
	Date:  		April 25, 2022.
	Purpose: 	Menu for condo owner to manage occupants
********************************************************************/
#include "melauderda42_prog4.h"

int main()
{
    int maxHeroes = 0;
    int currentResidence = 0; // Current residence of the condo

    // Creating heroes array
    cout << "\n\nHow many superheroes can live in your condo complex?" << endl;
    cin >> maxHeroes;
    cin.ignore();
    Heroes * heroArray; 
    heroArray = new Heroes[maxHeroes]; 

    // Creating the Menu
    string userSelection = "0";
    while (userSelection != "5")
    {
        cout << "\n\n\n\nWhat would you like to do?\n";
        cout << "\t\t1. Enter some superheroes" << endl;
        cout << "\t\t2. Delete a superhero" << endl;
        cout << "\t\t3. Print all superheroes" << endl;
        cout << "\t\t4. Print rent details" << endl;
        cout << "\t\t5. End program" << endl;
        cout << "\t\tEnter 1, 2, 3, 4, or 5." << endl;
        cout << "CHOICE: ";
        cin >> userSelection;
        cin.ignore();
        
        // Input Validation 
        while ((userSelection != "1") && (userSelection != "2") && (userSelection != "3") && (userSelection != "4") && (userSelection != "5"))
        {
            cout << "\nINVALID SELECTION, ENTER ONLY 1, 2, 3, 4, OR 5: ";
            cin >> userSelection;
            cin.ignore();
        }

        if (userSelection == "1")
        {
            currentResidence = enterHeroes(maxHeroes, currentResidence, heroArray);
        }      

        if (userSelection == "2")
        {
            deleteHero(currentResidence, heroArray);
        } 

        if (userSelection == "3")
        {
            printHeroes(currentResidence, heroArray);
        }

        if (userSelection == "4")
        {
            printRentDetails(currentResidence, heroArray);
        }

        if (userSelection == "5")
        {
            break;
        }
    }

    saveToFile(currentResidence, heroArray);

    delete [] heroArray;
    return 0;
}