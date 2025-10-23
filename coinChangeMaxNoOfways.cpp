#include<iostream>
#include<vector>
using namespace std;

int CoinChangeMaxNoOfWays(vector<int>& coins,int sum,int n,vector<vector<int>>& memo){
    if(sum==0) return 1;
    if(n==0) return 0;
    if(memo[n][sum] != -1) return memo[n][sum];

    if(coins[n-1]<=sum){
        memo[n][sum] = CoinChangeMaxNoOfWays(coins,sum-coins[n-1],n,memo)
                       + CoinChangeMaxNoOfWays(coins,sum,n-1,memo);
    } else {
        memo[n][sum] = CoinChangeMaxNoOfWays(coins,sum,n-1,memo);
    }
    return memo[n][sum];
}

int bottomupCoinChangeMaxNoOfWays(vector<int>& coins, int sum, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if (i==0){
                dp[i][j]=0;
            }
            else if (j==0){
                dp[i][j]=1;
        }
        else if(coins[i-1]<=j){
            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
        
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

}

int main(){
    int n;
    cout<<"Enter number of coins: ";
    cin >> n;
    vector<int> coins(n);
    cout<<"Enter the coins: ";
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    int sum;
    cout<<"Enter the target sum: ";
    cin >> sum;

    vector<vector<int>> memo(n+1, vector<int>(sum+1, -1));
    int maxWays = CoinChangeMaxNoOfWays(coins,sum,n,memo);
    cout<<"max number of ways to get sum: "<<maxWays<<endl;
   
    int maxWaysBottomUp = bottomupCoinChangeMaxNoOfWays(coins, sum, n);
    cout<<"(Bottom-Up) max number of ways to get sum: "<<maxWaysBottomUp<<endl;
}