// Problem: Find the contiguous subarray with the maximum sum
// Given an integer array nums, find the contiguous subarray with the largest sum

#include <iostream>
using namespace std;

int maxSubArray(int arr[], int n) {
    int maxSum = arr[0], currSum = arr[0];
    for (int i = 1; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum Subarray Sum: " << maxSubArray(arr, n);
    return 0;
}
