#include<iostream>
using namespace std;

int fib_tabulation(int fib[],int n){


if(n==0 || n==1){
    return n;
}
for(int i=2;i<=n;i++){
    fib[i]=fib[i-1]+fib[i-2];
}

return fib[n];


}

int fib_memorization(int fib[],int n){

if(n==0 || n==1){
    return n;
}

else{

    if(fib[n-1]==-1){

        fib[n-1]=fib_memorization(fib,n-1);
    }
    if(fib[n-2]==-1){
         fib[n-2]=fib_memorization(fib,n-2);
    }

    return fib[n-1]+fib[n-2];

}



}


int main(){

int n;
cin>>n;

int fib[n+1];

fib[0]=0;
fib[1]=1;

for(int i=2;i<=n;i++){
    fib[i]=-1;
}



cout<<fib_memorization(fib,n);


}
