#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rodCut(const vector<int>& price, int n)
{
    if (n <= 0) {
        return 0;
    }

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int max_val = 0;
        for (int j = 1; j <= i; j++)
        {
            if (j - 1 < price.size()) {
                max_val = max(max_val, price[j - 1] + dp[i - j]);
            }
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main()
{
    vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = 4;

    cout << "Profit is " << rodCut(price, n) << endl;

    return 0;
}
