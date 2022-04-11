#include <iostream>
// 993. Cousins in Binary Tree
// In a binary tree, the root node is at depth 0, and children of each depth k
// node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have
// different parents.

// We are given the root of a binary tree with unique values, and the values x
// and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are
// cousins.

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
	bool isCousins(TreeNode *root, int x, int y)
	{

		pair<int, int> cousin1, cousin2;
		cousin1 = recursiveFind(root, x, 0, 0);
		cousin2 = recursiveFind(root, y, 0, 0);

		if (cousin1.first != cousin2.first && cousin1.second == cousin2.second)
		{
			return true;
		}
		return false;
	}

	pair<int, int> recursiveFind(TreeNode *root, int num, int parent, int depth)
	{
		if (root == nullptr)
		{
			return make_pair(-1, -1);
		}

		if (root->val == num)
		{
			return make_pair(parent, depth);
		}
		else
		{
			pair<int, int> temp;
			temp = recursiveFind(root->left, num, root->val, depth + 1);
			if (temp.first != -1)
			{
				return temp;
			}
			temp = recursiveFind(root->right, num, root->val, depth + 1);
			return temp;
		}
	}
};
