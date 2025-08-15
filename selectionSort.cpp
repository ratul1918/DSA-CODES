#include <iostream>
using namespace std;

// Function to perform selection sort
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minIdx = i; // Why do we assume the current index is the minimum?

        for (int j = i+1; j < n; j++)
        {
            // Why are we comparing arr[j] with arr[minIdx]?
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // What happens if two elements are equal?
            }
        }

        // Swapping the smallest element found with the first unsorted element
        int temp = arr[minIdx]; 
        arr[minIdx] = arr[i];
        arr[i] = temp; // Can we use std::swap instead of this manual swap?
    }
}
// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Should we print a newline at the end for better readability?
    }
}

// Main function
int main() {
    int n;
    cin >> n; // What if the user inputs a very large number?

    int arr[n]; // Is this variable-length array safe in all compilers?

    for(int i = 0; i < n; i++) {
        cin >> arr[i]; // Should we validate the input?
    }

    SelectionSort(arr, n); // Why do we sort before printing?
    printArray(arr, n);

    return 0;
}
 
