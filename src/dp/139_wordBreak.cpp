/*
 * 139_wordBreak.cpp
 *	Word Break
 *  Created on: Apr 26, 2022
 *      Author: ganzo
 */
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * 1. Put the array of string into set. So that it can be checked with O(1)
 * time.
 * 2. Recursively check the string index from 0 till last index.
 * 3. if substr found in the set, look the next substr from the last index.
 * 4. keeps track whether string breaks or not in each index;
 */

using namespace std;
class Solution
{
	bool recursive_break(string &s, set<string> &word_set, int index,
						 vector<int> &memo)
	{
		if (index >= s.size())
		{
			return true;
		}
		if (memo[index] >= 0)
		{
			return memo[index];
		}
		bool temp = false;
		for (int i = index; i < s.size(); i++)
		{
			auto it = word_set.find(s.substr(index, i - index + 1));
			if (it != word_set.end())
			{
				// string found, check further
				if (recursive_break(s, word_set, i + 1, memo))
				{
					temp = true;
					break;
				}
			}
		}
		memo[index] = temp;
		return temp;
	}

  public:
	bool wordBreak(string s, vector<string> &wordDict)
	{
		set<string> word_set;
		vector<int> memo(s.size(), -1);
		for (string str : wordDict)
		{
			word_set.insert(str);
		}
		return recursive_break(s, word_set, 0, memo);
	}
};
int main()
{
	Solution sol;
	vector<string> word_list = {"leet", "code"};
	string input = "leetcode";
	cout << sol.wordBreak(input, word_list) << endl;
	return 0;
}
