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
	bool isDuplicate(vector<vector<int>> &result, vector<int> &currArr)
	{
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i][0] == currArr[0] && result[i][1] == currArr[1] &&
				result[i][2] == currArr[2])
			{
				return true;
			}
		}
		return false;
	}

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

		// for (int i=0; i<nums.size()-2; i++) {
		//     for (int j=i+1; j<nums.size()-1; j++) {
		//         for (int k=j+1; k<nums.size(); k++) {
		//             if (nums[i]+nums[j]+nums[k] == 0) {
		//                 temp[0] = nums[i];
		//                 temp[1] = nums[j];
		//                 temp[2] = nums[k];
		//                 if (!isDuplicate(result, temp)) {
		//                     result.push_back(temp);
		//                 }
		//             }
		//         }
		//     }
		// }
		return result;
	}
};
