#include<iostream>
using namespace std;
//turnary
/*int main(){

    int n=-45;

    cout<<(n>=0 ? "pos" : "neg")<<endl;


}*/

int main(){

    int n;
    int evenSum=0;
    cout<<"enter number to sum: ";
    cin>>n;

   for(int i=1;i<=n;i++){
    if(i%2 ==0){
        evenSum+=i;

    }


   }
   cout<<evenSum<<endl;

}