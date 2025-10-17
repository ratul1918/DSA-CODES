// Climbing Stairs Problem - Uses Fibonacci Sequence with Dynamic Programming
// To reach step n, you can come from step (n-1) or step (n-2)
// So ways(n) = ways(n-1) + ways(n-2) which is the Fibonacci pattern
#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main() {
    int n;
    cout << "Climbing Stairs Problem" << endl;
    cout << "You can climb either 1 or 2 steps at a time." << endl;
    cout << "Enter number of stairs: ";
    cin >> n;
    
    int ways = climbStairs(n);
    cout << "Number of distinct ways to climb " << n << " stairs: " << ways << endl;
    
    cout << "\nExplanation:" << endl;
    cout << "To reach stair " << n << ", you can either:" << endl;
    cout << "- Take 1 step from stair " << (n-1) << endl;
    cout << "- Take 2 steps from stair " << (n-2) << endl;
    cout << "So total ways = ways(" << (n-1) << ") + ways(" << (n-2) << ")" << endl;
    
    return 0;
}