#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<int>& v, const vector<int>& w, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (w[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - w[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> v(n), w(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << "Enter weights: ";
    for (int i = 0; i < n; ++i) cin >> w[i];
    cout << "Enter knapsack capacity: ";
    cin >> W;
    
    int result = knapsack(v, w, n, W);
    cout << "Maximum knapsack value is " << result << endl;
    
    return 0;
}