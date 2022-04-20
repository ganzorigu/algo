/*
 * 96_numTrees.cpp
 *	Unique Binary Search Trees
 *  Created on: Apr 13, 2022
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
	int numRecursive(int n, vector<int> &dp)
	{
		if (n <= 2)
		{
			return n;
		}
		if (dp[n])
		{
			return dp[n];
		}
		int left = 0;
		int right = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			left = numRecursive(i, dp);
			right = numRecursive(n - i - 1, dp);
			int temp = left * right;
			if (!temp)
			{
				sum += left + right;
			}
			else
			{
				sum += temp;
			}
		}
		dp[n] = sum;
		return sum;
	}

  public:
	int numTrees(int n)
	{
		vector<int> dp(n + 1, 0);
		return numRecursive(n, dp);
	}
};

int main()
{
	Solution sol;
	int res;
	res = sol.numTrees(6);
	cout << "result:" << res << endl;
	return 0;
}
