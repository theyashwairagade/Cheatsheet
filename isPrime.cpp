#include <iostream>
#include <cmath> 
using namespace std;

// NOTE: gap between two prime numbers is very low for less than 10^9 it is at max 292
bool isPrime(int number) {
    if (number <= 1) 
        return false; // 0 and 1 are not prime numbers
    if (number <= 3) 
        return true; // 2 and 3 are prime numbers
    if (number % 2 == 0 || number % 3 == 0)
        return false; // Multiple of 2 or 3 are not prime
    
    // Check for factors up to the square root of the number
    for (int i = 5; i * i <= number; i += 6) 
        if (number % i == 0 || number % (i + 2) == 0) 
            return false;
    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout<<isPrime(num);

    return 0;
}