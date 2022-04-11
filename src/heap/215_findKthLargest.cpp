/*
 * 215. Kth Largest Element in a Array - Medium
 * */

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
	int findKthLargest(vector<int> &nums, int k)
	{
		// O(nlogn)
		//         sort(nums.begin(), nums.end());
		//         return nums[nums.size()-k];

		// O(nlogk)
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < nums.size(); i++)
		{
			if (pq.size() < k)
			{
				pq.push(nums[i]);
			}
			else
			{
				int min_elem = pq.top();
				if (min_elem < nums[i])
				{
					pq.pop();
					pq.push(nums[i]);
				}
			}
		}
		return pq.top();
	}
};
