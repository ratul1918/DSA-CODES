#include<iostream> // Include input-output stream library

using namespace std;

int main() {

    int a = 10; // Initialize variable 'a' with value 10

    // Pre-decrement: Decrease 'a' by 1 first, then assign it to 'b'
    int b = --a;

    // Output the value of 'b'. It will be 9 because 'a' was decremented before assignment
    cout << b << endl;

    // Output the value of 'a'. It is also 9 after pre-decrement
    cout << a << endl;

    return 0; // Indicate successful program termination
}
