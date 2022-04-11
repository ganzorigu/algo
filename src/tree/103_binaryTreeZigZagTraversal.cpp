// 103. Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of
// its nodes' values. (i.e., from left to right, then right to left for the next
// level and alternate between).

// Explanation:
// used two stacks<pair<TreeNode*, int>>, pair stores the node and current
// level. used two stack pointers, when changing levels, need to swap the
// pointers. one pointer points to current level, other points to lower level.
// loop will end when both stack is empty
// when level is changed, direction "dir" is inversed.

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right)
		: val(x), left(left), right(right)
	{
	}
};

class Solution
{
  public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{

		vector<vector<int>> result;
		if (root == nullptr)
		{
			return result;
		}

		pair<TreeNode *, int> currNodeAndLevel;
		TreeNode *currNode;
		int level;
		stack<pair<TreeNode *, int>> st1;
		stack<pair<TreeNode *, int>> st2;
		bool dir = true;

		stack<pair<TreeNode *, int>> *currSt, *lowSt, *temp;
		currSt = &st1;
		lowSt = &st2;
		currSt->push(make_pair(root, 0));

		while (!st1.empty() || !st2.empty())
		{
			if (currSt->empty())
			{
				// stack that currSt is empty. which means we visited all curr
				// level nodes; need to move to next level;
				temp = currSt;
				currSt = lowSt;
				lowSt = temp;
			}

			currNodeAndLevel = currSt->top();
			currNode = currNodeAndLevel.first;
			level = currNodeAndLevel.second;
			if (result.size() <= level)
			{
				result.push_back({currNode->val});
				dir = !dir;
				// cout << endl;
			}
			else
			{
				result[level].push_back(currNode->val);
			}
			// cout << currNode->val << ", ";
			//  based on the dir, either start from left or right node;
			if (dir)
			{
				if (currNode->right)
				{
					lowSt->push(make_pair(currNode->right, level + 1));
				}
				if (currNode->left)
				{
					lowSt->push(make_pair(currNode->left, level + 1));
				}
			}
			else
			{
				if (currNode->left)
				{
					lowSt->push(make_pair(currNode->left, level + 1));
				}
				if (currNode->right)
				{
					lowSt->push(make_pair(currNode->right, level + 1));
				}
			}
			currSt->pop();
		}
		return result;
	}
};
