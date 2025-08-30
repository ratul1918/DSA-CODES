#include<iostream> // Include standard input-output library
using namespace std;

int main(){
    int n;
    bool isPrime = true; // Assume the number is prime initially.

    cout << "Enter testing number: "; // Ask user for input..
    cin >> n; // Read the input number

    // Prime numbers are greater than 1
    if (n <= 1) {
        isPrime = false;
    } else {
        // Loop from 2 to sqrt(n) to check if n is divisible by any number
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = false; // Found a divisor, so not prime
                break; // No need to check further
            }
        }
    }

    // Print the result based on isPrime flag
    if (isPrime) {
        cout << "Number is prime";
    } else {
        cout << "Number is not prime";
    }

    return 0;
}
