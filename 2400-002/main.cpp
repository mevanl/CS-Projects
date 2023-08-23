#include <iostream>
#include <string>
#include "string.h"

int euclidGCD(int, int);

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

            if (isdigit(curr_Char) == false) {
                std::cout << "Invalid command line arguments. Must be two integers seperated by a space." << std::endl;
                return 0;
            }
        }
    }

    int gcd;

    // Convert command line arguments to integers
    int m = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);

    gcd = euclidGCD(m, n);
    std::cout << "GCD is: " << gcd << std::endl;

    return 0;
}

/*
 *  euclidGCD is the extended implementation of euclid's GCD algorithm.
 *  Parameters: int m and n, can be positive or negative integers.
 */
int euclidGCD(int m, int n) {

    // Can not divide 0 by 0, this is undefined.
    if ((m == 0) && (n == 0)) {
        std::cout << "Undefined, can not divide 0 by 0." << std::endl;
        exit(1);
    }

    // Changes negative to positive, it is same GCD as if it was positive.
    if (m < 0) {
        m = m * (-1);
    }
    if (n < 0) {
        n = n * (-1);
    }

    // Base case, GCD found.
    if (n == 0) {
        return m;
    }
    // Recursive case
    int r = m % n;
    return euclidGCD(n, r);
}
