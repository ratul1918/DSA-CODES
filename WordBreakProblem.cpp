#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	vector<string> dictonary = { "this", "th", "is", "famous", "Word", "break",
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	unordered_set<string> dict(dictonary.begin(), dictonary.end());

	string s = "Wordbreakproblem";
	int n = (int)s.size();

	vector<vector<string>> dp(n + 1);
	dp[0].push_back(""); 

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (!dp[j].empty()) {
				string word = s.substr(j, i - j);
				if (dict.find(word) != dict.end()) {
					for (const string &prev : dp[j]) {
						if (prev.empty()) dp[i].push_back(word);
						else dp[i].push_back(prev + " " + word);
					}
				}
			}
		}
	}

	if (dp[n].empty()) {
		cout << "No valid segmentation found" << endl;
	} else {
		for (const auto &sentence : dp[n]) {
			cout << sentence << endl;
		}
	}

	return 0;
}