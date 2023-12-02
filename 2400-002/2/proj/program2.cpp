/*
    Title:      Traveling Salesman, Cheapest Flight Path
    Author:     Mason Lauderdale, melauderda42
    Date:       11/5/2023
    Purpose:    Traveling Salesman - find the lowest cost
                tour when traveling from US to 8 other countries
                and then back to US.

*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "GraphMatrix.h"
using namespace std;


// Global Constants
const int SIZE = 10; 
const string COUNTRY_CODES[SIZE] = {"AU", "BR", "CA", "CN", "GL", "IT", "NA", "RU", "US", "US"};


// Struct a single tour combination 
struct Tour
{
    string tour[SIZE];
    int cost;
};


// Function Protoptyes 
int searchCountryCode(string);
GraphMatrix* readFileMakeMatrix();
void printStringArray(string*, int);
Tour tourGenerate(string*, GraphMatrix*);
int cheapestTour(Tour*);
bool generatePermutation(string*, int);



int main()
{
    Tour* tourPermutations = new Tour[40320];       // All possible Tour Permutations 
    GraphMatrix* matrix = readFileMakeMatrix();     // Our Weighted Adjacency Matrix 
    string* countries = new string[SIZE-2];         // Countries to be visited, except US 


    // Print out the countries to be visited 
    cout << "\n\n*************************COUNTRIES*******************\n";
    for(int i = 0; i < SIZE-2; i++)
	{
		countries[i] = COUNTRY_CODES[i];
		cout << countries[i] << endl;
	}


    // Use Lexicographic Permute Algorithm to generate all possible tours
    cout << "\n\nLEXICOGRAPHIC ALGORITHM\n" << endl;
    int numPermutations = 0;
    do 
    {
        // pass current permutation into tour struct generator, and continue generating permutations
        Tour newTour = tourGenerate(countries, matrix);
        tourPermutations[numPermutations] = newTour;
        numPermutations++;
        cout << numPermutations << ": ";
        printStringArray(countries, SIZE-2);
        cout << "with cost: $" << tourPermutations[numPermutations-1].cost << endl;
        
        if (numPermutations == 40320)
        {
            break;
        }

    } while (generatePermutation(countries, SIZE-2));

    // Print Cheapest Tour 
    cout << "\n\n*************************SOLUTION*******************\n";
    int cheap = cheapestTour(tourPermutations);
    cout << "The cheapest tour with a price of $" << tourPermutations[cheap].cost << " is: ";
    printStringArray(tourPermutations[cheap].tour, 10);
    cout << "\n\nHappy Traveling!\n";


    // TODO: Release Memory 
    delete[] tourPermutations;
    delete[] countries;
    delete matrix;

    return 0;
}


int searchCountryCode(string code)
{
/*
	Parameters: a string with the country code like "BR"
	Returns:    an integer representing this country's index in the GraphMatrix,
                GraphMatrix lines up with the COUNTRY_CODES array, so we will 
                search that with Binary Search, since it is sorted alphbetically. 
*/ 
    int left = 0;
    int right = 10;

    while (left <= right) 
    {
        int middle = (left + right) / 2;

        if (COUNTRY_CODES[middle] == code)
        {
            return middle;
        }

        if (COUNTRY_CODES[middle] < code)
        {
            left = middle + 1;
        }

        else
        {
            right = middle - 1;
        }
    }
    return -1;
}


GraphMatrix* readFileMakeMatrix()
{
/*
	Purpose:    this function will read the data in flights.txt and create an
	            adjacency matrix with the couuntry codes.  The matrix values will be the
	            cost of the flights.
*/

	ifstream inFile;
	GraphMatrix * matrix = new GraphMatrix(SIZE-1);
	cout << "\nCreated the matrix.";
	string country1, country2;
	int price;
	inFile.open("flights.txt");
	cout << "\nReading from flights.txt\n";
	if(inFile)
	{
		while(inFile >> country1)
		{
			inFile >> country2;
			inFile >> price;
			//add price to graph matrix
			matrix->addEdge(searchCountryCode(country1), searchCountryCode(country2), price);
			cout << "\nAdded edge from " << country1 << " to " << country2 << " with cost of $" << price;
		}
	}
	else
		cout << "\nSorry, I am unable to open the file.\n";
	inFile.close();
	cout << "\n\nFLIGHT PRICE GRAPH MATRIX\n";
	matrix->printGraph();
	cout << endl;
	return matrix;
}


void printStringArray(string* arr, int size)
{
/* 
    Parameters: an array and its size
	Purpose:    this function will print the array of strings with a space
		        between each string
*/

	for(int x=0; x<size; x++)
	{
		cout << arr[x] << " ";
	}
}


Tour tourGenerate(string* tourPerm, GraphMatrix* matrix)
{
/*
    Parameters: A permutation of countries and the matrix to lookup weight
	Purpose:    Generate the tour struct with its price 
    Returns:    A proper tour struct 
*/
    Tour newTour;
    int cost = 0; 

    // Constant first and last country
    newTour.tour[0] = "US";
    newTour.tour[9] = "US";
    

    // Add Codes to the tour struct
    for (int i = 0; i < SIZE; i++)
    {
        if (i != 0 && i != 9)
        {
            newTour.tour[i] = tourPerm[i-1]; 
        }

    }

    // Add up all the cost in completed tour route
    for (int i = 0; i < SIZE-1; i++)
    {
        int code1 = searchCountryCode(newTour.tour[i]);
        int code2 = searchCountryCode(newTour.tour[i+1]);

        cost = cost + matrix->getWeight(code1, code2);
    }

    newTour.cost = cost;

    return newTour;
}


int cheapestTour(Tour* tours) 
{
/*
    Parameters: array/pointer of all tours
    Purpose:    Find cheapest (smallest weight) of an array of tours sent 
    Returns: index of the cheapest tour
*/
    int cheapest = 0;

    for (int i = 1; i < 40320; i++)
    {
        if (tours[cheapest].cost > tours[i].cost) 
        {
            cheapest = i;
        }
    }

    return cheapest;
}

bool generatePermutation(string* countries, int size)
{
/*
    Parameters: a country permutation, size of that permutation 
    Purpose:    generate a new permutation lexicographically from pervious 
    Returns:    bool based on whether final permutation or not
*/

    // Find the Lower Bound 
    int i = size - 2;
    while (countries[i] >= countries[i + 1])
    {
        i--;
    }
    // If no lower bound, no more possible permutations 
    if (i < 0)
    {
        return false;
    }

    // Find upper bound 
    int j = size - 1;
    while (countries[j] <= countries[i])
    {
        j--;
    }

    // swap the upper and lower and reverse the countries 
    swap(countries[i], countries[j]);
    reverse(countries + i + 1, countries + size);

    return true;
}