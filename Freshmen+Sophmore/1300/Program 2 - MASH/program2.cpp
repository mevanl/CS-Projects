/*******************************************************************
	Title: 		program2.cpp
	Author: 	Mason Lauderdale
	Date:  		Mar 1, 2022.
	Purpose: 	MASH game
********************************************************************/

#include <iostream> 
#include <string> 
using namespace std;

int displayMenuGetChoice();

int main()
{
    bool execution;
    
    do 
    {
        // Menu
        int userChoice = displayMenuGetChoice();
        cin.ignore();
        switch (userChoice)
        {
            case 1:
                execution = true;
                break;
            case 2: 
                execution = false;
                break;
        }
        if (execution == false)
            break;

        // Variable Defintions
        int userMASH = 0;
        string userHouse = "";

        string personLike1 = "";
        string personLike2 = "";
        string personDislike = "";
        int randPersonNum = 0;
        string userPerson = "";

        int smallNumber1 = 0;
        int smallNumber2 = 0;
        int smallNumber3 = 0;
        int randSmallNumberNum = 0;
        int userSmallNum = 0;

        string locationLike1 = "";
        string locationLike2 = "";
        string locationDislike = "";
        int randLocationNum = 0;
        string userLocation = "";

        string jobLike1 = "";
        string jobLike2 = "";
        string jobDislike = "";
        int randJobNum = 0;
        string userJob = "";

        string companyOrRestaurantLike1 = "";
        string companyOrRestaurantLike2 = "";
        string companyOrRestaurantDislike = "";
        int randCompRestNum = 0;
        string userCompRest = "";

        int largeNumber1 = 0;
        int largeNumber2 = 0;
        int largeNumber3 = 0;
        int randLargeNum = 0;
        int userLargeNum = 0;

        string carLike1 = "";
        string carLike2 = "";
        string carDislike = "";
        int randCarNum = 0;
        string userCar = "";


        // User Inputs

            // People
        cout << "\n\nEnter a person you like: ";
        getline(cin, personLike1);
        cout << "Enter another person you like: ";
        getline(cin, personLike2);
        cout << "Enter a person you dislike: ";
        getline(cin, personDislike);

            // Numbers between 1 - 100
        cout << "\nEnter three numbers that are between 1 and 100, seperated by a space: ";
        cin >> smallNumber1 >> smallNumber2 >> smallNumber3;
        cin.ignore();
                // Invalid Input Checking
        while ((smallNumber1 < 1) || (smallNumber1 > 100))
        {
            cout << "Invalid Input! Enter an integer 1 - 100!\n";
            cin >> smallNumber1;
            cin.ignore();
        }
        while ((smallNumber2 < 1) || (smallNumber2 > 100))
        {
            cout << "Invalid Input! Enter an integer 1 - 100!\n";
            cin >> smallNumber2;
            cin.ignore();
        }
        while ((smallNumber3 < 1) || (smallNumber3 > 100))
        {
            cout << "Invalid Input! Enter an integer 1 - 100!\n";
            cin >> smallNumber3;
            cin.ignore();
        }  

            // Cities
        cout << "\nEnter a City, State that you like: ";
        getline(cin, locationLike1);
        cout << "Enter another City, State that you like: ";
        getline(cin, locationLike2);
        cout << "Enter a City, State that you dislike: ";
        getline(cin, locationDislike);

            // Jobs
        cout << "\nEnter a job title you would like to have: ";
        getline(cin, jobLike1);
        cout << "Enter another job title you would like to have: ";
        getline(cin, jobLike2);
        cout << "Enter a job title you would not like to have: ";
        getline(cin, jobDislike);

            // Company and Restaurants
        cout << "\nEnter a company or restaurant you like: ";
        getline(cin, companyOrRestaurantLike1);
        cout << "Enter another company or restaurant you like: ";
        getline(cin, companyOrRestaurantLike2);
        cout << "Enter a company or restaurant you dislike: ";
        getline(cin, companyOrRestaurantDislike);

            // Numbers between 10,000 - 50,000
        cout << "\nEnter three numbers that are between 10,000 and 50,000, seperated by a space: ";
        cin >> largeNumber1 >> largeNumber2 >> largeNumber3;
        cin.ignore();
                // Invalid Input Checking
        while ((largeNumber1 < 10000) || (largeNumber1 > 50000))
        {
            cout << "Invalid Input! Enter an integer 10000 - 50000!\n";
            cin >> largeNumber1;
            cin.ignore();
        }
        while ((largeNumber2 < 10000) || (largeNumber2 > 50000))
        {
            cout << "Invalid Input! Enter an integer 10000 - 50000!\n";
            cin >> largeNumber2;
            cin.ignore();
        }
        while ((largeNumber3 < 10000) || (largeNumber3 > 50000))
        {
            cout << "Invalid Input! Enter an integer 10000 - 50000!\n";
            cin >> largeNumber3;
            cin.ignore();
        }
            // Cars
        cout << "\nEnter a car you would like to have: ";
        getline(cin, carLike1);
        cout << "Enter another car you would like to have: ";
        getline(cin, carLike2);
        cout << "Enter a car you would not like to have: ";
        getline(cin, carDislike);


        // Random Number Generation 
        userMASH = rand() % 4 + 1;
        randPersonNum = rand() % 3 + 1;
        randSmallNumberNum = rand() % 3 + 1;
        randLocationNum = rand() % 3 + 1;
        randJobNum = rand() % 3 + 1;
        randCompRestNum = rand() % 3 + 1;
        randLargeNum = rand() % 3 + 1;
        randCarNum = rand() % 3 + 1;


        // Calculations 

            // Type of House
        if (userMASH == 1) 
            userHouse = "mansion";
        else if (userMASH == 2)
            userHouse = "apartment";
        else if (userMASH == 3)
            userHouse = "shack";
        else if (userMASH == 4)
            userHouse = "house";

            // Spouse
        if (randPersonNum == 1)
            userPerson = personLike1;
        else if (randPersonNum == 2)
            userPerson = personLike2;
        else if (randPersonNum == 3)
            userPerson = personDislike;

            // Number of Children
        if (randSmallNumberNum == 1)
            userSmallNum = smallNumber1;
        else if (randSmallNumberNum == 2)
            userSmallNum = smallNumber2;
        else if (randSmallNumberNum == 3)
            userSmallNum = smallNumber3;

            // Location 
        if (randLocationNum == 1)
            userLocation = locationLike1;
        else if (randLocationNum == 2)
            userLocation = locationLike2;
        else if (randLocationNum == 3)
            userLocation = locationDislike;

            // User Company or Restaurant
        if (randCompRestNum == 1)
            userCompRest = companyOrRestaurantLike1;
        else if (randCompRestNum == 2)
            userCompRest = companyOrRestaurantLike2;
        else if (randCompRestNum == 3)
            userCompRest = companyOrRestaurantDislike;

            // User Job Title
        if (randJobNum == 1)
            userJob = jobLike1;
        else if (randJobNum == 2)
            userJob = jobLike2;
        else if (randJobNum == 3)
            userJob = jobDislike;

            // Salary
        if (randLargeNum == 1)
            userLargeNum = largeNumber1;
        else if (randLargeNum == 2)
            userLargeNum = largeNumber2;
        else if (randLargeNum == 3)
            userLargeNum = largeNumber3;

            // User's Car
        if (randCarNum == 1)
            userCar = carLike1;
        else if (randCarNum == 2)
            userCar = carLike2;
        else if (randCarNum == 3)
            userCar = carDislike;
        

        // Output 
        cout << "\n\n\n******* MASH RESULTS *******\n" << endl;
        cout << "You will live in a " << userHouse << ".\n";
        cout << "You will be happily married to " << userPerson << ".\n";
        cout << "You and your spouse will have " << userSmallNum << ".\n";
        cout << "You will live at " << userLocation << ".\n";
        cout << "You will work at " << userCompRest << " as a " << userJob << " and make $" << userLargeNum << " a year.\n";
        cout << "You will drive a " << userCar << ".\n\n\n";
    } while (execution == true);
    
    return 0;
}

int displayMenuGetChoice() 
{
    int userMenu;
    cout << "\nPick from the Following:\n\t1. Play MASH!\n\t2. Exit the program.\n";
    cin >> userMenu;

    while ((userMenu != 1) && (userMenu != 2)) {
        cout << "Invalid Input, Please Enter either 1 or 2.\n";
        cin >> userMenu;
    }
    return userMenu;

}