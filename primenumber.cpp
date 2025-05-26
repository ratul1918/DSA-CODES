#include<iostream>
using namespace std;

int main(){
    int n;
    bool isPrime=true;
    cout<<"enter testing number: ";
    cin>>n;

    for(int i=2; i*i <= n-1 ;i++){
        if(n%i == 0){
            isPrime=false;
            break;
        }

    }

    if(isPrime== true){
        cout<<"number is prime";
    }
    else{
        cout<<"number is not prime";
    }

}