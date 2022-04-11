// 15. 3Sum

// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero.

// Notice that the solution set must not contain duplicate triplets.

// Solution: sort the array.

// after that start

#include <algorithm> // std::sort
#include <iostream>	 // std::cout
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> result;

		if (nums.size() < 3)
		{
			return result;
		}
		sort(nums.begin(), nums.end());
		int sum;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			while (i != 0 && nums[i] == nums[i - 1] && i < nums.size() - 2)
			{
				i++;
			} // to avoid duplicacy from beginning

			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k)
			{
				sum = nums[i] + nums[j] + nums[k];
				if (sum == 0)
				{
					result.push_back({nums[i], nums[j], nums[k]});
					while (j < k && nums[j] == nums[j + 1] &&
						   nums[k] == nums[k - 1]) // to avoid duplicacy within
												   // start and end
					{
						j++;
						k--;
					}
					// if (!isDuplicate(result, temp)) {
					//      result.push_back(temp);
					// }
					j++;
					k--;
				}
				else if (sum > 0)
				{
					k--;
				}
				else if (sum < 0)
				{
					j++;
				}
			}
		}
		return result;
	}
};
