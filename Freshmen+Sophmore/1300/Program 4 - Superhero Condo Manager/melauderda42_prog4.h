/*******************************************************************
	Title: 		melauderda42_prog4.h
	Author: 	Mason Lauderdale, melauderda42
	Date:  		April 25, 2022.
	Purpose: 	Hold libraries, structures, prototypes for the program
********************************************************************/
#ifndef MLAUDERDA42_PROG4_H
#define MLAUDERDA42_PROG4_H

// Libraries
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

// Structures
struct Rent // Holds Information about Hero's Rent
{
    float rentCost; // Cost of Hero's Rent 
    float damageCost; // Cost of Hero's Damage
    float yearsLived; // Years lived in Condo
};

struct Heroes // Holds information about the Hero
{
    string heroName;
    string heroDescription;
    bool heroDanger;
    Rent rentInfo;
};

// Prototypes
int enterHeroes(int, int, Heroes[]);
void deleteHero(int&, Heroes[]);
bool moveArrayElements(string, int, Heroes[]);
void printHeroes(int, Heroes[]);
void printRentDetails(int, Heroes[]);
void saveToFile(int, Heroes[]);

#endif