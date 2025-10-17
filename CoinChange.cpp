#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int findMinCoins(const vector<int>& S, int target)
{
    vector<int> dp(target + 1, target + 1);
    dp[0] = 0;

    for (int i = 1; i <= target; ++i)
    {
        for (int coin : S)
        {
            if (i >= coin)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[target] > target) ? -1 : dp[target];
}

int main()
{
    vector<int> S = { 1, 2, 3, 4 };
    int target = 15;

    int coins = findMinCoins(S, target);
    if (coins != -1)
    {
        cout << "The minimum number of coins required to get the desired change is "
             << coins << endl;
    }
    else
    {
        cout << "It's not possible to make the desired change." << endl;
    }

    return 0;
}
