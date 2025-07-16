#include<iostream> // Include the input-output stream .
using namespace std;

int main(){
    int n;
    cout << "Enter line number: "; // Prompt the user to enter the number of lines (n x n matrix).
    cin >> n; // Read the number from user input

    int num = 1; // Initialize a variable to start printing numbers from 1

    // Outer loop controls the number of rows
    for (int i = 0; i < n; i++) {
        // Inner loop controls the number of columns
        for (int j = 0; j < n; j++) {
            cout << num << " "; // Print the current number followed by a space
            num++; // Increment the number for the next cell
        }
        cout << endl; // Move to the next line after each row is printed
    }
}

