/*******************************************************************
	Title: 		melauderda42_functions.cpp
	Author: 	Mason Lauderdale, melauderda42
	Date:  		April 25, 2022.
	Purpose: 	All Functions needed for menu and operations
********************************************************************/
#include "melauderda42_prog4.h"

// User can enter Heroes manually or via files
int enterHeroes(int maxHeroes, int currentResidence, Heroes arr[])
{
    if (maxHeroes == currentResidence)
    {
        cout << "\n\nSorry! Your complex can only hold " << maxHeroes << " heroes.\nYou cannot add more.\n\n";    
    }
    else 
    {
        string choice = "0";
        cout << "\n\nWhat do you want to do?" << endl;
        cout << "\t1. Load the heroes from a file." << endl;
        cout << "\t2. Enter a hero manually." << endl;
        cout << "CHOICE: ";
        cin >> choice;
        cin.ignore();
        while ((choice != "1") && (choice != "2"))
        {
            cout << "INVALID INPUT! PLEASE ENTER 1 OR 2: " << endl;
            cin >> choice;
            cin.ignore();
        }
        if (choice == "1")
        {
            string filename;
            cout << "What is the name of the file with your list of superheroes? (ex: filename.txt)" << endl;
            cout << "FILENAME: ";
            getline(cin, filename);
            ifstream inputFile;
            inputFile.open(filename);
            if (!inputFile.is_open()) // Check if file opened properly
            {
                cout << "\n\nFailed to open " << filename << ". file either Doesn't exist or is corrupted." << endl;
            }
            else // add heroes to array
            {
                string tempString;
                int heroesInFile = 0;
                int addedHeroes = 0;
                // Finds out how many pieces of information are in the file 
                while(getline(inputFile, tempString, '#'))
                {
                    heroesInFile++;
                }
                // Divide by 6 (6 pieces of info per hero) will give us the # of heroes in the file
                heroesInFile = heroesInFile/6; 
                cout << "\n\nThere are " << heroesInFile << " heroes in " << filename << ".";
                inputFile.clear();
                inputFile.seekg(0);

                for(int i = currentResidence; addedHeroes != heroesInFile; i++)
                {
                    getline(inputFile, arr[i].heroName, '#');
                    getline(inputFile, arr[i].heroDescription, '#');
                    string tempDanger = "";
                    getline(inputFile, tempDanger, '#');
                    if (tempDanger == "1")                              
                    {                                                   
                        istringstream("1") >> arr[i].heroDanger;        // bool can be represented by 0 and 1, so string to int to bool conversions
                    } 
                    else if (tempDanger == "0")
                    {
                        istringstream("0") >> arr[i].heroDanger;
                    }
                    string tempRent = "";
                    getline(inputFile, tempRent, '#');
                    arr[i].rentInfo.rentCost = stof(tempRent); // casting string to float
                    string tempDamage = "";
                    getline(inputFile, tempDamage, '#');
                    arr[i].rentInfo.damageCost = stof(tempDamage);
                    string tempYears = "";
                    getline(inputFile, tempYears, '#');
                    arr[i].rentInfo.yearsLived = stof(tempYears);
                    currentResidence++;
                    addedHeroes++;     
                }
                cout << "\n" << addedHeroes << " Heroes from " << filename << " now live in the condo.\n";
            }
        }
        else if (choice == "2")
        {
            char manualHero = 'y';
            while(manualHero == 'y')
            {
                // Keep checking too make sure no overflow of the array
                if (maxHeroes == currentResidence)
                {
                    cout << "\nSorry! Your complex can only hold " << maxHeroes << " heroes.\nYou cannot add more." << endl;
                    manualHero = 'n';
                    break;
                }
                // Entering Hero data
                cout << "\nSUPERHERO NAME: ";
                getline(cin, arr[currentResidence].heroName);
                cout << "\n\nDESCRIPTION: ";
                getline(cin, arr[currentResidence].heroDescription);
                cout << "\n\nIS THE HERO DANGEROUS (y or n): ";
                char dangerCheck;
                cin >> dangerCheck;
                cin.ignore();
                if (dangerCheck == 'y')
                {
                    arr[currentResidence].heroDanger = true;
                }
                else if (dangerCheck == 'n')
                {
                    arr[currentResidence].heroDanger = false;
                }
                cout << "\n\n\nHow much rent does " << arr[currentResidence].heroName << " pay per month?" << endl;
                cout << "RENT PRICE:\t$";
                cin >> arr[currentResidence].rentInfo.rentCost;
                cin.ignore();
                cout <<"\n\nWhat is the typical cost of damage " << arr[currentResidence].heroName << " has per month?" << endl;
                cout << "DAMAGE COST:\t$";
                cin >> arr[currentResidence].rentInfo.damageCost;
                cin.ignore();
                cout << "\n\nHow many years has " << arr[currentResidence].heroName << " lived in your condo?" << endl;
                cout << "YEARS:\t";
                cin >> arr[currentResidence].rentInfo.yearsLived;
                cin.ignore();
                cout << "\n\nSuperhero " << arr[currentResidence].heroName << " has been added.\n" << endl;
                currentResidence++;

                cout << "Want to add more heroes? (y or n): ";
                cin >> manualHero;
                cin.ignore();
            }
            
        }
    }
    return currentResidence;
}

// Delete a hero 
void deleteHero(int &currentResidence, Heroes arr[])
{
    string deleteName;
    cout << "\n\nThe following is a list of all the heroes in you condo complex:\n";
    for(int i = 0; i < currentResidence; i++)
    {
        cout << arr[i].heroName << endl;
    }
    cout << "\n\nWhich hero are you kicking out of your complex?" << endl;
    cout << "SUPERHERO NAME: ";
    getline(cin, deleteName);
    if (moveArrayElements(deleteName, currentResidence, arr) == true)
    {
        cout << "\n\nYou have removed " << deleteName << ".\n" << endl;
        currentResidence--;
    }
    else 
    {
        cout << "\n\nSorry, a hero by the name " << deleteName << " was not found.\n" << endl; 
    }
}

// Shift elements of the array to the left when deleting
bool moveArrayElements(string heroName, int currentResidence, Heroes arr[])
{
    bool returnBool;
    int deleteIndex = 0;
    for(int i = 0; i < currentResidence; i++)
    {
        if (heroName == arr[i].heroName)
        {
            deleteIndex = i;
            for(int j = deleteIndex; j < currentResidence; ++j)
            {
                arr[j] = arr[j + 1];
            }
            returnBool = true;
            return true;
            break;
        }
    }
    if (arr[deleteIndex].heroName != heroName)
    {
        returnBool = false;
        return false;
    }
    return returnBool;
}

// Print all Heroes in the Heroes Array in a readable format
void printHeroes(int currentResidence, Heroes arr[])
{
    for(int i = 0; i < currentResidence; i++)
    {
      cout << "\n\n-----------------------------------------------------------------------------" << endl;
      cout << "----------------------------------SUPERHERO " << i+1 << endl;  
      cout << "NAME:\t\t" ;
      cout << arr[i].heroName;
      cout << "\nDESCRIPTION: ";
      cout << "\n" << arr[i].heroDescription;
      cout << "\nDANGEROUS:\t";
      if (arr[i].heroDanger == true)
      {
          cout << "YES";
      }
      else 
      {
          cout << "NO";
      }
      cout << "\nRENT PRICE:\t" << setw(20);
      cout << "$ " << arr[i].rentInfo.rentCost << setw(10);
      cout << "\nDAMAGE COST:\t" << setw(20);
      cout << "$ " << arr[i].rentInfo.damageCost << setw(10);
      cout << "\nYEARS:\t\t" << setw(20);
      cout << arr[i].rentInfo.yearsLived << setw(10);
      cout << "\n\n";
    }
}

// Loops through Array and prints information regarding rent
void printRentDetails(int currentResidence, Heroes arr[])
{
    cout << "\n\nRENT DETAILS FOR EACH HERO: \n\n";
    float rentTotal = 0;
    float damageTotal = 0;
    int x;
    cout << "SUPERHERO";
    cout.width(35);
    cout << "MONTHLY RENT";
    cout.width(35);
    cout << "DAMAGE COST\n";
    cout << fixed << showpoint;
    cout << setprecision(2);
    for(int i = 0; i < currentResidence; i++)
    {
        cout << left;
        cout.width(30);
        cout << arr[i].heroName;
        cout << "$"; 
        cout << right;
        cout.width(13);
        cout << arr[i].rentInfo.rentCost;
        cout.width(22);
        cout << "$"; 
        cout << right;
        cout.width(12);
        cout << arr[i].rentInfo.damageCost;
        cout << "\n";

        rentTotal += arr[i].rentInfo.rentCost;
        damageTotal += arr[i].rentInfo.damageCost;
    }
    cout << "-----------------------------------------------------------------------------\n\n";
    cout << "TOTALS:";
    cout.width(24);
    cout << "$";
    cout << right;
    cout.width(13);
    cout << rentTotal;
    cout.width(22);
    cout << "$";
    cout << right;
    cout.width(13);
    cout << damageTotal;
    cout << "\n";
}

// Takes Array and saves it to a file
void saveToFile(int currentResidence, Heroes arr[])
{
    char userChoice;
    cout << "\n\n\nWould you like to save your superheroes list to a file? (y or n): ";
    cin >> userChoice;
    cin.ignore();
    if (userChoice == 'y')
    {
        ofstream outputFile;
        string filename;
        cout << "What is the name of the file you want to save your superheroes to?" << endl;
        cout << "FILENAME:\t";
        getline(cin, filename);
        outputFile.open(filename);

        for(int i = 0; i < currentResidence; i++)
        {
            outputFile << arr[i].heroName << "#" << arr[i].heroDescription << "#" << arr[i].heroDanger << "#"
            << arr[i].rentInfo.rentCost << "#" << arr[i].rentInfo.damageCost << "#" << arr[i].rentInfo.yearsLived << "#";
        }

        cout << "\n\nYour superheroes were successfully saved to the " << filename << " file." << endl;
        outputFile.close();
    }
    else if (userChoice == 'n')
    {
        cout << "\n\n\n\nGoodbye!";
    }
}