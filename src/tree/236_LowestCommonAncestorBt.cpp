// 236. Lowest Common Ancestor of a Binary Tree
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
// in the tree.

// According to the definition of LCA on Wikipedia: â€œThe lowest common
// ancestor is defined between two nodes p and q as the lowest node in T that
// has both p and q as descendants (where we allow a node to be a descendant of
// itself).â€?

// Solution. used the same solution as lowestCommonAncestorBST.
// Because this solution is general solution.

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
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		vector<TreeNode *> leftAncestors;
		vector<TreeNode *> rightAncestors;

		recursiveTraverse(root, p, leftAncestors);
		recursiveTraverse(root, q, rightAncestors);

		vector<TreeNode *> *olderNode;
		vector<TreeNode *> *youngerNode;

		if (leftAncestors.size() > rightAncestors.size())
		{
			olderNode = &rightAncestors;
			youngerNode = &leftAncestors;
		}
		else
		{
			olderNode = &leftAncestors;
			youngerNode = &rightAncestors;
		}
		for (int i = 0; i < olderNode->size(); i++)
		{
			for (int j = 0; j < youngerNode->size(); j++)
			{
				if (((*olderNode)[i])->val == ((*youngerNode)[j])->val)
				{
					return (*olderNode)[i];
				}
			}
		}
		return nullptr;
	}

	bool recursiveTraverse(TreeNode *root, TreeNode *p, vector<TreeNode *> &arr)
	{

		if (root == nullptr)
		{
			return false;
		}

		if (root->val == p->val)
		{
			// node is found
			arr.push_back(root);
			return true;
		}

		if (!root->left && !root->right)
		{
			return false;
		}

		if (recursiveTraverse(root->left, p, arr) ||
			recursiveTraverse(root->right, p, arr))
		{
			arr.push_back(root);
			return true;
		}
		return false;
	}
};
