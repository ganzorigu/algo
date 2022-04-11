// 98. Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search
// tree (BST).

// A valid BST is defined as follows:

//     The left subtree of a node contains only nodes with keys less than the
//     node's key. The right subtree of a node contains only nodes with keys
//     greater than the node's key. Both the left and right subtrees must also
//     be binary search trees.

// Solution explanation.
// need to define upper bound and lower bound
// So that child nodes shouldn't go over from that bound
// input value can go up to INT_MAX, INT_MIN, Therefore upper, lower bound
// should be long value. And initial value should be (long)(INT_MAX)+1,
// (long)(INT_MIN)-1
#include <iostream>
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
	bool isValidRecursion(TreeNode *root, long leftBound, long rightBound)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (!root->left && !root->right)
		{
			return true;
		}

		if (root->left)
		{
			if (root->val <= (root->left)->val)
			{
				return false;
			}

			// check lower and upper bound
			if ((root->left)->val <= leftBound ||
				(root->left)->val >= rightBound)
			{
				return false;
			}

			// since it is left node, leftbound should not change, upper bound
			// is currNode value;
			if (!isValidRecursion(root->left, leftBound, root->val))
			{
				return false;
			}
		}

		if (root->right)
		{
			if (root->val >= (root->right)->val)
			{
				return false;
			}

			if ((root->right)->val <= leftBound ||
				(root->right)->val >= rightBound)
			{
				return false;
			}

			// since it is right node, rightbound should not change, leftBound
			// should is currNode value;
			if (!isValidRecursion(root->right, root->val, rightBound))
			{
				return false;
			}
		}
		return true;
	}

	bool isValidBST(TreeNode *root)
	{
		if (!root->left && !root->right)
		{
			return true;
		}
		if (root->left)
		{
			if (root->val <= (root->left)->val)
			{
				return false;
			}
			// need to define initial bounds
			if (!isValidRecursion(root->left, (long)INT_MIN - 1, root->val))
			{
				return false;
			}
		}

		if (root->right)
		{
			if (root->val >= (root->right)->val)
			{
				return false;
			}
			// need to define initial bounds
			if (!isValidRecursion(root->right, root->val, (long)INT_MAX + 1))
			{
				return false;
			}
		}
		return true;
	}
};
