// 560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the total number of
// continuous subarrays whose sum equals to k.

// Solution use hashmap<int,int> (sum, occurence)
#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
	int subarraySum(vector<int> &nums, int k)
	{
		// time limit exceeded
		//         int i=0;
		//         int sum = 0;
		//         int count = 0;
		//         int begin = 0;

		//         while(begin<nums.size()) {
		//             sum = sum + nums[i++];
		//             if (sum==k) {
		//                 count++;
		//             }
		//             if (i==nums.size()) {
		//                 begin++;
		//                 sum=0;
		//                 i=begin;
		//             }
		//         }
		//         return count;

		// using hashmap
		if (nums.size() == 0)
		{
			return 0;
		}

		// hash map key is the current sum,
		// value is the occurence.
		unordered_map<int, int> umap;
		int sum = 0;
		int count = 0;
		umap[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (umap.find(sum - k) != umap.end())
			{
				count += umap[sum - k];
			}
			umap[sum]++;
		}

		return count;
	}
};
