#include<iostream>
using namespace std;

// Function to perform Bubble Sort on the array
void Bubblesort(int arr[], int n) {
    // Outer loop for number of passes
    for(int i = 0; i < n - 1; i++) {
        // Inner loop for pairwise comparison and swapping
        for(int j = 0; j < n - 1 - i; j++) {
            // Swap if current element is greater than the next
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print elements of the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;  // Input the size of array

    int arr[n];  // Declare array of size n

    // Input n elements into array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort array using Bubble Sort
    Bubblesort(arr, n);

    // Print sorted array
    printArray(arr, n);

    return 0;
}
