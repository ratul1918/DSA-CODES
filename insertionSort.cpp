#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // Should we check if n is positive?..

    int arr[n]; // Is it safe to use variable-length arrays in all compilers?...

    for(int i = 0; i < n; i++){
        cin >> arr[i]; // Should we validate if the input is an integer?..
    }

    // Why does the loop start from index 2 instead of 1?..
    for(int i = 2; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        // Why do we shift elements greater than key to the right?.
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // What happens if key is the smallest so far?...
    }

    // Output the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "; // Should we format the output differently (e.g., newline)?
    }
    cout << endl;

    return 0;
}
