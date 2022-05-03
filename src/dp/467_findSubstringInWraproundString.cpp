/*
 * 467_findSubstringInWraproundString.cpp
 *	Unique Substrings in Wraparound String
 *  Created on: May 3, 2022
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
	int getNumOfSubstring(string &str, int index, char prev_val)
	{
		char c_temp;
		char p_temp;
		int numOfSubstr = 1;
		for (int i = index + 1; i < str.length(); i++)
		{
			c_temp = (str[i] - 'a') % 26;
			p_temp = (prev_val + 1) % 26;
			/* check if current char is the one after previous */
			/* E.g 'xyzabcd....zabc' */
			if (p_temp == c_temp)
			{
				numOfSubstr++;
				prev_val = c_temp;
			}
			else
			{
				break;
			}
		}
		return numOfSubstr;
	}

  public:
	int findSubstringInWraproundString(string p)
	{
		/* array stores up to 26 indexes. whenever index value with higher count
		 * found, update the map*/
		vector<int> my_arr(26, 0);
		int num_of_substr = 0;
		/* memoization. always stores the count of previous index*/
		vector<int> memo(p.length(), 0);
		int temp;
		temp = getNumOfSubstring(p, 0, p[0] - 'a');
		memo[0] = temp;
		my_arr[p[0] - 'a'] = temp;
		for (int i = 1; i < p.length(); i++)
		{
			if (memo[i - 1] > 1)
			{
				temp = memo[i - 1] - 1;
			}
			else
			{
				temp = getNumOfSubstring(p, i, p[i] - 'a');
			}
			memo[i] = temp;
			my_arr[p[i] - 'a'] = max(my_arr[p[i] - 'a'], temp);
		}

		for (int i = 0; i < 26; i++)
		{
			num_of_substr += my_arr[i];
		}

		return num_of_substr;
	}
};

int main()
{
	int res;
	string str =
		"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
		"stuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghij"
		"klmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzab"
		"cdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst"
		"uvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
		"mnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd"
		"efghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"
		"wxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
		"opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef"
		"ghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
		"yzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
		"qrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefgh"
		"ijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
		"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
		"stuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghij"
		"klmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzab"
		"cdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst"
		"uvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
		"mnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	Solution sol;
	res = sol.findSubstringInWraproundString(str);
	cout << "result:" << res << endl;
	return 0;
}
