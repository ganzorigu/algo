// 1704. Determine if String Halves Are Alike
// You are given a string s of even length. Split this string into two halves of
// equal lengths, and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
// 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
// lowercase letters.

// Return true if a and b are alike. Otherwise, return false.

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	bool halvesAreAlike(string s)
	{
		char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

		int leftCnt = 0, rightCnt = 0;

		for (int i = 0; i < s.length() / 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (vowels[j] == s[i])
				{
					leftCnt++;
				}
			}
		}

		for (int i = s.length() / 2; i < s.length(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (vowels[j] == s[i])
				{
					rightCnt++;
				}
			}
		}

		if (rightCnt == leftCnt)
		{
			return true;
		}
		return false;
	}
};
