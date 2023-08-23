#include <iostream>

int euclidGCD(int, int);
int extendedEuclidGCD(int, int);

/* TODO: Implement command line arguments for m and n, make sure user is entering integers only*/
/* Test Cases: Two ints, m is smaller than n, n is negative, m is negative, one is zero, negative zero, float, etc*/

int main() {
    int gcd;
    int m = 31415;
    int n = 14142;

    gcd = euclidGCD(m, n);

    std::cout << "GCD is: " << gcd << std::endl;

    return 0;
}

/*
 *  euclidGCD is basic implementation of euclid's GCD algorithm.
 *  Parameters: int m and n, both must be positive integers.
 *              if they are not, will call the extended version
 *              with support for negative integers.
 */
int euclidGCD(int m, int n) {
    if (n == 0) {
        return m;
    }
    int r = m % n;
    return euclidGCD(n, r);
}

int extendedEuclidGCD(int m, int n) {
    return 0;
}