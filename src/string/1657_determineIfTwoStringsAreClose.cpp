// 1657. Determine if Two Strings Are Close
// Two strings are considered close if you can attain one from the other using
// the following operations:

//     Operation 1: Swap any two existing characters.
//         For example, abcde -> aecdb
//     Operation 2: Transform every occurrence of one existing character into
//     another existing character, and do the same with the other character.
//         For example, aacabb -> bbcbaa (all a's turn into b's, and all b's
//         turn into a's)

// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close,
// and false otherwise.

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	bool closeStrings(string word1, string word2)
	{

		if (word1.length() != word2.length())
		{
			// cout << "1st condition failed" << endl;
			return false;
		}

		unordered_map<char, int> umap1;
		unordered_map<char, int> umap2;

		for (char c : word1)
		{
			umap1[c]++;
		}
		for (char c : word2)
		{
			umap2[c]++;
		}

		// size of map is not equal, not same
		if (umap1.size() != umap2.size())
		{
			// cout << "2nd condition failed" << endl;
			return false;
		}

		// abbzzca
		// abbzzcz

		//         a - 2
		//         b - 2
		//         z - 2
		//         c - 1

		//         a - 1
		//         b - 2
		//         z - 3
		//         c - 1

		//         a - 2
		//         b - 3
		//         c - 1

		//         a - 1
		//         b - 2
		//         c - 3

		vector<int> w1;
		vector<int> w2;

		// at least key should exist.
		for (auto it = umap1.begin(); it != umap1.end(); ++it)
		{
			if (!umap2.count(it->first))
			{
				// cout << "last condition failed" << endl;
				return false;
			}
		}

		// convert map into vector
		for (auto it = umap1.begin(); it != umap1.end(); ++it)
		{
			w1.push_back(it->second);
		}

		// convert map into vector
		for (auto it = umap2.begin(); it != umap2.end(); ++it)
		{
			w2.push_back(it->second);
		}

		// sort
		sort(w1.begin(), w1.end());
		sort(w2.begin(), w2.end());

		// value should be equal
		for (int i = 0; i < w1.size(); i++)
		{
			if (w1[i] != w2[i])
			{
				return false;
			}
		}
		return true;
	}
};
