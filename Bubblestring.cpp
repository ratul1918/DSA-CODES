#include<iostream>
using namespace std;

void BubbleSort(string arr[], int n) {
    string temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(string arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    string arr[n];
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    BubbleSort(arr, n);

    cout << "\nSorted strings:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "\n";
    }

    return 0; 
}