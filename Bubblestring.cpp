#include<iostream>
using namespace std;

// Function to perform Bubble Sort on a string array
void BubbleSort(string arr[], int n) {
    string temp;
    // Outer loop for passes
    for(int i = 0; i < n - 1; i++) {
        // Inner loop for comparing adjacent elements
        for(int j = 0; j < n - 1 - i; j++) {
            // Swap if strings are in the wrong order
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array of strings
void printArray(string arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;

    // Ask user for the number of strings
    cout << "Enter the number of strings: ";
    cin >> n;

    // Declare array of strings
    string arr[n];

    // Input strings from user
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sort the strings using Bubble Sort
    BubbleSort(arr, n);

    // Display the sorted strings..
    cout << "\nSorted strings:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "\n";
    }

    return 0; 
}
