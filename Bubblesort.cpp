
#include<iostream>
using namespace std;

// Function to perform Bubble Sort on the array
void Bubblesort(int arr[], int n) {
    // Outer loop for number of passes
    for(int i = 0; i < n - 1; i++) {
        // Inner loop for pairwise comparison and swapping
        for(int j = 0; j < n - 1 - i; j++) {
            // Why do we compare only up to n - 1 - i? (What does this optimization do?)
            if(arr[j] > arr[j + 1]) {
                // Swapping elements if they are out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // Can we use std::swap(arr[j], arr[j+1]) instead?
            }
        }
        // Should we add a flag to check if any swap happened and break early if not?
    }
}

// Function to print elements of the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Should we add a newline after printing the array?
    }
}

int main() {
    int n;
    cin >> n;  // What if n is zero or negative?

    int arr[n];  // Is this Variable Length Array portable across all compilers?

    // Input n elements into array
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; // Should we check for valid integer input?
    }

    // Sort array using Bubble Sort
    Bubblesort(arr, n);

    printArray(arr, n);

    return 0;
}
