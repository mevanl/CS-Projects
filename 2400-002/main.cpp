/*
 * Name: Mason Lauderdale
 * Course: CSC 2400-002, Design of Algorithms
 * Date: 8/23/2023
 *
 * File: main.cpp
 * Project 1
 * Summary:
 *          Takes in two integers, type checked and negatives allowed, from the command line and runs puts them through
 *          multiple greatest common divisor algorithms (Euclidean, Consecutive Integer Checking, and 'Middle School
 *          Procedure') and neatly prints out the results to the console.
 */
#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <cmath>

// Function Prototypes
int euclidGCD(int, int&, int, int&);
int consecutiveIntegerCheckingGCD(int, int);
int middleSchoolGCD(int m, int n);
std::vector<int> primeFactorization(int);

int main(int argc, char *argv[]) {

    // If user has not put in 2 command line arguments
    if (argc != 3) {
        std::cout << "Insufficient command line arguments. Two integers seperated by space are required." << std::endl;
        return 1;
    }

    // Ensure the command line arguments are integers
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            // triggers if negative is in front of number, to ensure catches '-' in middle of argument (i.e. 2400-002)
            if (j == 0 && (argv[i][j] == '-')) {
                j++;
            }

            char curr_Char = argv[i][j];

            // If it's not a digit, thus not a number, this is not a valid integer.
            if (isdigit(curr_Char) == false) {
                std::cout << "Invalid command line arguments. Must be two integers seperated by a space." << std::endl;
                return 1;
            }
        }
    }

    int gcd;

    // Convert command line arguments to integers
    int m = std::stoi(argv[1]);
    int mCoefficient = 1;
    int n = std::stoi(argv[2]);
    int nCoefficient = 1;

    // Print results to console.
    gcd = euclidGCD(m, mCoefficient, n, nCoefficient);
    std::cout << "\nExtended Euclidean Algorithm " << "\n----------------------------" << "\nGCD: " << gcd <<
                 "\n\nCoefficient's multiplying to get the GCD (mx,ny): " << "\nx = " << mCoefficient <<
                 ", y = " << nCoefficient << std::endl;
    gcd = consecutiveIntegerCheckingGCD(m, n);
    std::cout << "\n\nConsecutive Integer Checking Algorithm" << "\n--------------------------------------" <<
                 "\nGCD: " << gcd << std::endl;
    gcd = middleSchoolGCD(m, n);
    std::cout << "\n\nMiddle School GCD Procedure" << "\n---------------------------" <<
              "\nGCD: " << gcd << std::endl;

    return 0;
}

/*
 *  euclidGCD is the extended implementation of Euclidean GCD algorithm.
 *  Parameters: int m and n, can be positive or negative integers.
 *              variables to receive the coefficients that multiple to get the GCD.
 */
int euclidGCD(int m, int& mCoefficient, int n, int& nCoefficient) {

    // Can not divide 0 by 0, this is undefined.
    if ((m == 0) && (n == 0)) {
        std::cout << "Undefined, can not divide 0 by 0." << std::endl;
        exit(1);
    }

    // Base case, GCD found.
    if (n == 0) {
        mCoefficient = 1;
        nCoefficient = 0;

        if (m < 0) {
            return (-1)*m;
        }
        return m;
    }
    // Recursive case

    // To be updated with the new coefficients when going up recursive chain to find the coefficients that give us gcd
    int mCoff1;
    int nCoff1;

    int gcd = euclidGCD(n, mCoff1, m % n, nCoff1);

    // Update with new coefficients
    mCoefficient = nCoff1;
    nCoefficient = mCoff1 - nCoff1 * (m / n);

    return gcd;
}

/*
 * consecutiveIntegerCheckingGCD is GCD algorithm that uses smaller integer and decrements until finds dividable number
 * Parameters: int m and n, can be positive or negative integers.
 */
int consecutiveIntegerCheckingGCD(int m, int n) {

    // Can not divide 0 by 0, this is undefined.
    if ((m == 0) && (n == 0)) {
        std::cout << "Undefined, can not divide 0 by 0." << std::endl;
        exit(1);
    }

    // In case one of the inputs if zero
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    // In case negative values
    if (m < 0) {
        m = (-1)*m;
    }
    if (n < 0) {
        n = (-1)*n;
    }

    // Find smaller integer
    int min;
    if (m >= n) {
        min = n;
    }
    else {
        min = m;
    }

    // Loop until both have remainder of 0 when divided by minimum for both integers
    while (true) {
        if ((m % min) == 0) {
            if ((n % min == 0)) {
                break;
            }
        }
        min--;
    }

    return min;
}

/*
 * middleSchoolGCD is GCD algorithm that multiples the integers shared primes to get to the GCD.
 * Parameters: int m and n, can be positive or negative integers.
 */
int middleSchoolGCD(int m, int n) {

    // Can not divide 0 by 0, this is undefined.
    if ((m == 0) && (n == 0)) {
        std::cout << "Undefined, can not divide 0 by 0." << std::endl;
        exit(1);
    }

    // In case one of the inputs if zero
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    // In case negative values
    if (m < 0) {
        m = (-1)*m;
    }
    if (n < 0) {
        n = (-1)*n;
    }

    // Get our vectors filled with prime factors
    std::vector<int> mPrimes = primeFactorization(m);
    std::vector<int> nPrimes = primeFactorization(n);

    std::vector<int> commonPrimes;

    // Iterate through each vector, finding duplicates, adding to common vector, and removing them so not recounted.
    if (mPrimes.size() >= nPrimes.size()) {
        for (int i = 0; i < nPrimes.size(); i++) {
            for (int j = 0; j < mPrimes.size(); j++) {
                while (nPrimes[i] == mPrimes[j]) {
                    commonPrimes.push_back(nPrimes[i]);
                    nPrimes.erase(nPrimes.begin() + i);
                    mPrimes.erase(mPrimes.begin() + j);
                }
            }
        }
    }
    else {
        for (int i = 0; i < mPrimes.size(); i++) {
            for (int j = 0; j < nPrimes.size(); j++) {
                while (mPrimes[i] == nPrimes[j]) {
                    commonPrimes.push_back(mPrimes[i]);
                    mPrimes.erase(mPrimes.begin() + i);
                    nPrimes.erase(mPrimes.begin() + j);
                }
            }
        }
    }

    int gcd = 1;

    // Multiple up all the prime factors, and you will get the GCD.
    for (int i = 0; i < commonPrimes.size(); i++) {
        gcd = gcd * commonPrimes[i];
    }

    return gcd;
}

/*
 * primeFactorization will return a vector of all the passed integer's prime factors.
 * Parameters: int num, any positive integer.
 */
std::vector<int> primeFactorization(int num) {
    std::vector<int> numPrimes;

    // If even, add all the 2's to prime vector
    while ((num % 2) == 0) {
        numPrimes.push_back(2);
        num = num / 2;
    }

    // All possible 2's have been added. The number now must be odd, So increment over even numbers in for loop
    for (int i = 3; i <= sqrt(num); i = i + 2) {
        while ((num % i) == 0) {
            numPrimes.push_back(i);
            num = num / i;
        }
    }

    // When num itself is a prime number larger than 2.
    if (num > 2) {
        numPrimes.push_back(num);
    }

    return numPrimes;
}