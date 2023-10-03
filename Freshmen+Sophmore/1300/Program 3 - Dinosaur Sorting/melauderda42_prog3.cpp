/*******************************************************************
	Title: 		melauderda42_prog3.cpp
	Author: 	Mason Lauderdale
	Date:  		April 5, 2022.
	Purpose: 	Sort an array of animals and categorize them correctly
********************************************************************/
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>

// Prototypes
int carnOrHerb(string);
bool searchCarnivore(string);
bool searchHerbivore(string);
void printDino(ofstream&, ifstream&, string, int[]);
bool overTenGrand(string);
void printResults(int[], string[]);

int main()
{
    // Variables
    int totalsArray[6] = {0, 0, 0, 0, 0, 0};
    string labelsArray[6] = {"TOTAL DINOS", "TOTAL CARNIVORE DINOS", "TOTAL HERBIVORE DINOS", 
                            "DINOS OVER 10,000 LBS", "DINO NAMES END IN 'SAURUS'", "ANIMALS NOT DINOS"};  
    ifstream directoryFile;
    string filename = "";
    string tempString = "";
    string saurusCheck = "saurus";


    // Opening Directory file
    cout << "Enter the Dinosaur Directory File Name (dinoDirectory.txt): ";
    cin >> filename;
    cin.ignore();
    directoryFile.open(filename);

    // Create Output Files
    ofstream carnOutFile;
    ofstream herbOutFile;
    ofstream otherOutFile;

    // Checking if Directory File has been opened
    while (directoryFile.is_open() == false)
    {
        cout << "\n\nThis file could not be opened! Please enter again (dinoDirectory.txt): ";
        cin >> filename;
        cin.ignore();
        directoryFile.open(filename);
    }
    cout << "\n\n";

    // Going thorugh and checking each animal
    while(getline(directoryFile, tempString, '#'))
    {
        // Does it contant 'saurus'?
        if (tempString.find(saurusCheck) != string::npos)
        {
            totalsArray[4] += 1;
        }
        // Is it a Carnivore, Herbivore, or Other?
        if (carnOrHerb(tempString) != 0)
        {
            if (carnOrHerb(tempString) == 1) // Carnivore
            {
                totalsArray[1] += 1;
                carnOutFile.open("carnOutFile.txt", ios::app);
                printDino(carnOutFile, directoryFile, tempString, totalsArray);
                carnOutFile.close();
                cout << tempString << " is being printed out to the CARNIVORE file!" << endl;
            }
            else if (carnOrHerb(tempString) == 2) // Herbivore
            {
                totalsArray[2] += 1;
                herbOutFile.open("herbOutFile.txt", ios::app);
                printDino(herbOutFile, directoryFile, tempString, totalsArray);
                herbOutFile.close();
                cout << tempString << " is being printed out to the HERBIVORE file!" << endl;
            }
            else if (carnOrHerb(tempString) == -1) // Other
            {
                totalsArray[5] += 1;
                otherOutFile.open("otherOutFile.txt", ios::app);
                printDino(otherOutFile, directoryFile, tempString, totalsArray);
                otherOutFile.close();
                cout << tempString << " is being printed out to the OTHER file!" << endl;
            }
        }
    }
    totalsArray[0] = totalsArray[1] + totalsArray[2];
    directoryFile.close();

    // Printing out the results
    cout << "\n\n";
    printResults(totalsArray, labelsArray);

    return 0; 
}

// Uses searchCarnivore and searchHerbivore functions to identify and return the animal's type
int carnOrHerb(string animalName)
{
    int animalType = 0;

    if (searchCarnivore(animalName) == true)
    {
        animalType = 1;
    }
    else if (searchHerbivore(animalName) == true)
    {
        animalType = 2;
    }
    else
    {
        animalType = -1;
    }
    return animalType; 
}

// Goes throught carnivore.txt too check if animal is present in file
bool searchCarnivore(string animalName)
{
    bool returnVal = false;
    string carnName;
    ifstream carnInFile;
    carnInFile.open("carnivores.txt");
    while(!carnInFile.eof())
    {
        getline(carnInFile, carnName, '#');
        if (carnName == animalName)
        {
            returnVal = true;
            break;
        }
    }
    carnInFile.close();
    return returnVal;
}

// Goes throught herbivore.txt too check if animal is present in file
bool searchHerbivore(string animalName)
{
    bool returnVal = false;
    string herbName;
    ifstream herbInFile;
    herbInFile.open("herbivores.txt");
    getline(herbInFile, herbName, '#');
    while(!herbInFile.eof())
    {
        getline(herbInFile, herbName, '#');
        if (herbName == animalName)
        {
            returnVal = true;
            break;
        }
    }
    herbInFile.close();
    return returnVal;
}

void printDino(ofstream &animalOutFile, ifstream &dinoDirectory, string animalName, int totalsArray[])
{
    string heightLength = "";
    string mass = "";
    string eats = "";
    string description = "";

    animalOutFile << "DINOSAUR NAME: " << animalName << endl;
    getline(dinoDirectory, heightLength, '#');
    animalOutFile << "HEIGHT/LEGNTH: " << heightLength << endl;
    getline(dinoDirectory, mass, '#');
    if (overTenGrand(mass) == true)
    {
        totalsArray[3] += 1;
    } 
    animalOutFile << "MASS: " << mass << endl;
    getline(dinoDirectory, eats, '#');
    animalOutFile << "EATS: " << eats << endl;
    getline(dinoDirectory, description, '#');
    animalOutFile << "DESCRIPTION: " << description << endl;
    animalOutFile << "\n";
}

bool overTenGrand(string mass)
{
    int dinoMass = 0;
    bool returnVal = false;

    // Removing lbs
    mass.erase(mass.find("l"), 3);
    mass.pop_back(); // Removing space before lbs
    // Removing to
    if (mass.find("t") != string::npos)
    {
        mass.erase(mass.find("t"), 3);
    }
    // Removing the first number, starts first index of string and goes to space, +1 to remove space.
    if (mass.find(" ") != string::npos)
    {
        mass.erase(0, mass.find_first_of(" ")+1);
    }
    // Removing comma
    if (mass.find(",") != string::npos)
    {
        mass.erase(mass.find(","), 1);
    }
    // Converting str to int
    dinoMass = stoi(mass);

    // Check if over 10 Grand
    if (dinoMass >= 10000)
    {
        returnVal = true;
    }
    return returnVal;
}

void printResults(int totalsArray[], string labelsArray[])
{
    string line(50, '-');
    cout << line << endl;

    for(int i = 0; i < 6; i++)
    {
        cout << setw(30) << labelsArray[i] << ":   " << totalsArray[i];
        cout << "\n";
    }
    cout << line;
}