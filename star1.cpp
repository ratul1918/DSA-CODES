#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter : ";
    cin >> n;

    // Outer loop controls the number of rows..
    for(int i = 0; i < n; i++){
        char ch = 'A';  // Start each row with character 'A'..

        // Inner loop prints characters from 'A' to the nth alphabet..
        for(int j = 0; j < n; j++){
            cout << ch;   // Print the current character
            ch = ch + 1;  // Move to the next character
        }

        cout << endl; // Move to the next line after each row..
    }

    return 0;
}
