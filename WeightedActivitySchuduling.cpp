#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end, profit;
};

int binarySearch(const vector<Job>& jobs, int index) {
    int left = 0, right = index - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (jobs[mid].end <= jobs[index].start) {
            if (jobs[mid + 1].end <= jobs[index].start)
                left = mid + 1;
            else
                return mid;
        } else
            right = mid - 1;
    }
    return -1;
}

int maxProfitDP(const vector<Job>& jobs) {
    int n = jobs.size();
    vector<int> dp(n);
    dp[0] = jobs[0].profit;
    
    for (int i = 1; i < n; i++) {
        int inclProf = jobs[i].profit;
        int latestNonConflict = binarySearch(jobs, i);
        if (latestNonConflict != -1)
            inclProf += dp[latestNonConflict];
        
        dp[i] = max(inclProf, dp[i-1]);
    }
    
    return dp[n-1];
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    
    vector<Job> jobs(n);
    cout << "Enter start time, end time, and profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
    }
    
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.end < b.end;
    });
    
    cout << "Maximum profit: " << maxProfitDP(jobs) << endl;
    
    return 0;
}