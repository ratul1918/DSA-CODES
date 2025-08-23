// Problem: Perform Binary Search on a sorted array.
// Given a sorted array and a target value, return the index if found, else return -1.

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int result = binarySearch(arr, n, target);
    cout << "Index: " << result << endl;
    return 0;
}


