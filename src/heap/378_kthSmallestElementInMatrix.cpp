/*
 * 378. Kth Smallest Element in a Sorted Matrix
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
	int kthSmallest(vector<vector<int>> &matrix, int k)
	{

		priority_queue<int, vector<int>> pq;

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (pq.size() < k)
				{
					pq.push(matrix[i][j]);
				}
				else
				{
					if (pq.top() > matrix[i][j])
					{
						pq.pop();
						pq.push(matrix[i][j]);
					}
				}
			}
		}
		return pq.top();
	}
};
