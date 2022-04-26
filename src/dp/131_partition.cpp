/*
 * 131_partition.cpp
 *  Palindrome Partitioning
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
	int check_palindrome(string &s, int s_i, int e_i)
	{
		int i = s_i;
		int j = e_i;

		while (i < j)
		{
			if (s[i] != s[j])
			{
				return 0;
			}
			i++;
			j--;
		}
		// palindrome
		return 1;
	}

  public:
	int recursive_check(string &s, vector<string> &arr,
						vector<vector<string>> &res, int start_i)
	{
		if (start_i >= s.size())
		{
			res.push_back(arr);
			return 1;
		}
		for (int i = start_i; i < s.size(); i++)
		{
			if (check_palindrome(s, start_i, i))
			{
				arr.push_back(s.substr(start_i, i - start_i + 1));
				recursive_check(s, arr, res, i + 1);
				arr.pop_back();
			}
		}
		return 0;
	}

	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> pal_set;
		vector<string> str_arr;
		recursive_check(s, str_arr, pal_set, 0);
		return pal_set;
	}
};

int main()
{
	Solution sol;
	vector<vector<string>> res;
	res = sol.partition("aab");

	for (auto str_set : res)
	{
		cout << "[";
		for (auto str : str_set)
		{
			cout << str << ' ';
		}
		cout << "]" << endl;
	}
}
