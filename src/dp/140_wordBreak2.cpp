/*
 * 140_wordBreak2.cpp
 *  Word Break 2
 *  Created on: Apr 28, 2022
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
/*
 * 1. Put the array of string into set. So that it can be checked with O(1)
 * time.
 * 2. Recursively check the string index from 0 till last index.
 * 3. if substr found in the set, append the sentence with found string
 * 4. once the whole sentence if built, recursively remove the added words
 * 5. And check for next possible word.
 */

class Solution
{
	void recursive_check(string &s, unordered_set<string> &my_set,
						 int start_index, string &sentence,
						 vector<string> &sentence_set)
	{
		if (start_index >= s.size())
		{
			sentence_set.push_back(sentence.substr(0, sentence.size() - 1));
			return;
		}

		for (int i = start_index; i < s.size(); i++)
		{
			string temp_str = s.substr(start_index, i - start_index + 1);
			auto it = my_set.find(s.substr(start_index, i - start_index + 1));
			if (it != my_set.end())
			{
				// string found
				sentence.append(temp_str + " ");
				recursive_check(s, my_set, i + 1, sentence, sentence_set);
				sentence.resize(sentence.size() - (i - start_index + 2));
			}
		}
		return;
	}

  public:
	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		unordered_set<string> my_set;
		string sentence;
		vector<string> sentence_set;
		my_set.insert(wordDict.begin(), wordDict.end());
		recursive_check(s, my_set, 0, sentence, sentence_set);
		return sentence_set;
	}
};

int main()
{
	Solution sol;
	string input_str = "catsanddog";
	vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
	vector<string> res;
	res = sol.wordBreak(input_str, wordDict);

	cout << "[";
	for (string s : res)
	{
		cout << s << ",";
	}
	cout << "]" << endl;

	return 0;
}
