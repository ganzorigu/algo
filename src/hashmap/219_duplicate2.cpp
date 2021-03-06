#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	bool containsNearbyDuplicate(vector<int> &nums, int k)
	{
		unordered_map<int, int> umap;

		for (int i = 0; i < nums.size(); i++)
		{
			if (umap.find(nums[i]) == umap.end())
			{
				umap[nums[i]] = i;
			}
			else
			{
				if (abs(umap[nums[i]] - i) <= k)
				{
					return true;
				}
				umap[nums[i]] = i;
			}
		}
		return false;
	}
};
