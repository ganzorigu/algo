// 709. To Lower Case
// Implement function ToLowerCase() that has a string parameter str, and returns
// the same string in lowercase.

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	string toLowerCase(string str)
	{
		string ans;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				ans.push_back('a' + (str[i] - 'A'));
			}
			else
			{
				ans.push_back(str[i]);
			}
		}
		return ans;
	}
};
