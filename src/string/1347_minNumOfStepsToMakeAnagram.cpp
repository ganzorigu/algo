// 1347. Minimum Number of Steps to Make Two Strings Anagram
// Given two equal-size strings s and t. In one step you can choose any
// character of t and replace it with another character.

// Return the minimum number of steps to make t an anagram of s.

// An Anagram of a string is a string that contains the same characters with a
// different (or the same) ordering.

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	int minSteps(string s, string t)
	{

		unordered_map<char, int> umap;
		int count = 0;
		for (char c : s)
		{
			umap[c]++;
		}

		for (char c : t)
		{
			if (umap.find(c) != umap.end() && umap[c] > 0)
				umap[c]--;
			else
				count++;
		}
		return count;

		//         int totalChanges = s.length();

		//         unordered_map<char, int> umap1;
		//         unordered_map<char, int> umap2;

		//         for (char c : s) {
		//             if (!umap1.count(c)) {
		//                 umap1.insert({c,1});
		//             } else {
		//                 umap1[c] = umap1[c] + 1;
		//             }
		//         }

		// //         l - 1
		// //         e - 3
		// //         t - 1
		// //         c - 1
		// //         o - 1
		// //         d - 1

		// //         p - 1
		// //         r - 1
		// //         a - 1
		// //         c - 2
		// //         t - 1
		// //         i - 1
		// //         e - 1

		//          for (char c : t) {
		//             auto it = umap1.find(c);
		//             if (it != umap1.end()) {
		//                 if (umap1[c] > 0){
		//                     umap1[c] = umap1[c] - 1;
		//                     totalChanges--;
		//                 }

		//             }
		//         }
		//         return totalChanges;
	}
};
