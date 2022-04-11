// 257. Binary Tree Paths
// Given a binary tree, return all root-to-leaf paths.
// Note: A leaf is a node with no children.

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
	vector<string> binaryTreePaths(TreeNode *root)
	{
		vector<string> result;

		if (root == nullptr)
		{
			return result;
		}
		recursiveTraversing(root, result, "", true);
		return result;
	}
	void recursiveTraversing(TreeNode *root, vector<string> &result,
							 string temp, bool isRoot)
	{
		if (root == nullptr)
		{
			return;
		}
		string tStr = temp;
		if (!isRoot)
		{
			tStr += "->";
		}
		tStr += to_string(root->val);
		if (!root->left && !root->right)
		{
			// leaf is found
			result.push_back(tStr);
		}
		else
		{
			recursiveTraversing(root->left, result, tStr, false);
			recursiveTraversing(root->right, result, tStr, false);
		}
	}
};
