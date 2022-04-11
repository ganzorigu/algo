/*
 * 107. Binary Tree Level Order Traversal II
 * */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root). no need
// to return vector, if working with reference, no need to return this value; it
// increases the execution time and memory

// O(n) solution
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
	vector<vector<int>> levelOrderBottom(TreeNode *root)
	{
		vector<vector<int>> myList;
		recursiveTraversal(root, myList, 0);
		reverse(myList.begin(), myList.end());
		return myList;
	}

	void recursiveTraversal(TreeNode *root, vector<vector<int>> &myList,
							int index)
	{
		if (root == nullptr)
		{
			return;
		}

		if (index == myList.size())
		{
			myList.push_back({root->val});
		}
		else
		{
			myList[index].push_back(root->val);
		}

		recursiveTraversal(root->left, myList, index + 1);
		recursiveTraversal(root->right, myList, index + 1);
	}
};
