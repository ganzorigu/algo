/*
 * 466_countRepetitions.cpp
 * Count the Repetitions
 *  Created on: May 2, 2022
 *      Author: ganzo
 */
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
	bool isSubsequence(string &s, string &t)
	{
		int char_found;
		int t_index = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char_found = 0;
			for (int j = t_index; j < t.size(); j++)
			{
				if (s[i] == t[j])
				{
					t_index = j + 1;
					char_found = 1;
					break;
				}
			}
			if (!char_found)
			{
				return false;
			}
		}
		return true;
	}

  public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2)
	{
		string *str1;
		string *str2;
		if (s2.size() > s1.size())
		{
			return 0;
		}

		if (s1.size() >= s2.size())
		{
			str1 = &s2;
			str2 = &s1;
		}
		else
		{
			str1 = &s1;
			str2 = &s2;
		}

		if (isSubsequence(*str1, *str2))
		{
			return min(n1, n2);
		}
		return 0;
	}
};

int main()
{
	//	string s1 = "acb";
	//	int n1 = 4;
	//	string s2 = "ab";
	//	int n2 = 2;
	string s1 = "acb";
	int n1 = 1;
	string s2 = "acb";
	int n2 = 1;

	Solution sol;

	cout << "result:" << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;
	return 0;
}
