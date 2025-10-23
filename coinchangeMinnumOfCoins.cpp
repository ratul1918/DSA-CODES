#include<iostream>
#include<vector>
using namespace std;

int minNumberOfCoins(vector<int>& coins,int sum,int n){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,INT_MAX-1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=INT_MAX-1;
            }
            else if(coins[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum]==INT_MAX-1?-1:dp[n][sum];

}

int main(){
    int n;
    cout<<"enter number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout<<"enter the coins: ";
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    int sum;
    cout<<"enter the target sum: ";
    cin >> sum;
    int minCoins=minNumberOfCoins(coins,sum,n);
    if(minCoins==-1){
        cout<<"Not possible to form the sum with given coins"<<endl;
    }
    else{
        cout<<"Minimum number of coins to form the sum: "<<minCoins<<endl;
    }
}