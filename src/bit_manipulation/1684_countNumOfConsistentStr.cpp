/*
 * countNumOfConsistentStr.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: ganzo
 */
/*
 * 1684. Count the number of consistent string
 *
 * */
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
	char arr_map[26] = {0};

  public:
	int countConsistentStrings(string allowed, vector<string> &words)
	{
		int count = 0;
		int temp = 0;
		for (uint32_t i = 0; i < allowed.size(); i++)
		{
			arr_map[allowed[i] - 'a'] = 1;
		}
		for (auto word : words)
		{
			temp = 1;
			for (auto character : word)
			{
				if (arr_map[character - 'a'] == 0)
				{
					temp = 0;
					break;
				}
			}
			count += temp;
		}
		return count;
	}
};

int main()
{

	string allowed = "ab";
	vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
	// result should be 2;
	Solution sol;

	cout << "Result: " << sol.countConsistentStrings(allowed, words) << endl;
	return 0;
}
