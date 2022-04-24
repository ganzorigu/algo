/*
 * 115_numDistinct.cpp
 * Distinct Subsequences
 *  Created on: Apr 23, 2022
 *      Author: ganzo
 */
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
	int recursiveNumDistinct(string &s, string &t, int index_s, int index_t,
							 vector<vector<int>> &dp)
	{
		if (t.size() == index_t)
		{
			return 1; // string found
		}

		if (s.size() - index_s < t.size() - index_t)
		{
			return 0; // no need to check further
		}
		if (s.size() == index_s)
		{
			return 0; // string not found
		}
		if (dp[index_s][index_t] >= 0)
		{
			return dp[index_s][index_t];
		}

		int sum = 0;
		for (int i = index_s; i < s.size(); i++)
		{
			if (s[i] == t[index_t])
			{
				sum += recursiveNumDistinct(s, t, i + 1, index_t + 1, dp);
			}
		}
		dp[index_s][index_t] = sum;
		return sum;
	}

  public:
	int numDistinct(string s, string t)
	{
		vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
		return recursiveNumDistinct(s, t, 0, 0, dp);
	}
};

int main()
{
	string s = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaea"
			   "bdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
	string t = "bddabdcae";
	//	string s = "babgbag";
	//	string t = "bag";
	//	string s = "rabbbit";
	//	string t = "rabbit";
	Solution sol;

	cout << "result:" << sol.numDistinct(s, t) << endl;
	return 0;
}
