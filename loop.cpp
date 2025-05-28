#include<iostream> // Include the input-output stream
using namespace std;

// Ternary operator example (currently commented out)
/*
int main(){
    int n = -45;

    // Check if the number is positive or negative using ternary operator
    cout << (n >= 0 ? "pos" : "neg") << endl;

    return 0;
}
*/

// Program to calculate the sum of even numbers up to 'n'
int main(){
    int n;
    int evenSum = 0; // Variable to store the sum of even numbers

    cout << "Enter number to sum: "; // Prompt user for input
    cin >> n; // Read the number

    // Loop from 1 to n
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {  // Check if the number is even
            evenSum += i;  // Add even number to the sum
        }
    }

    // Print the total sum of even numbers
    cout << "Sum of even numbers from 1 to " << n << " is: " << evenSum << endl;

    return 0;
}
