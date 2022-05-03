// 392. Is Subsequence
// A subsequence of a string is a new string that is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (i.e., "ace" is a
// subsequence of "abcde" while "aec" is not).

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// class Solution
//{
//   public:
//	bool isSubsequence(string s, string t)
//	{
//		if (s.length() == 0)
//		{
//			return true;
//		}
//
//		int i = 0;
//		int j = 0;
//		while (t.length() - j >= s.length() - i)
//		{
//			if (s[i] == t[j])
//			{
//				i++;
//				j++;
//				if (i == s.length())
//				{
//					return true;
//				}
//			}
//			else
//			{
//				j++;
//			}
//		}
//		// cout << "i:" << i << endl;
//		// cout << "j:" << j << endl;
//		return false;
//	}
// };

class Solution
{
  public:
	bool isSubsequence(string s, string t)
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
};
