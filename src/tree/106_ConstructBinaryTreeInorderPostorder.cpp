// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder
// traversal of a binary tree and postorder is the postorder traversal of the
// same tree, construct and return the binary tree.

// postorder is left right root
// inorder is left root right

// inorder = [9,3,15,20,7],
// postorder = [9,15,7,20,3],
// 3 is root, that means, left nodes are 9, right nodes are 15,20,7
// 20 is next root node that is right node 3. 15 is the left node, 7 is the
// right node.

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
	int index;

  public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		index = postorder.size() - 1;
		return recursiveBuildTree(inorder, postorder, 0, index);
	}

	TreeNode *recursiveBuildTree(vector<int> &inorder, vector<int> &postorder,
								 int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}
		TreeNode *root = new TreeNode(postorder[index--]);
		if (left == right)
		{
			return root;
		}
		int foundIndex = searchIndex(inorder, left, right, root->val);
		root->right =
			recursiveBuildTree(inorder, postorder, foundIndex + 1, right);
		root->left =
			recursiveBuildTree(inorder, postorder, left, foundIndex - 1);

		return root;
	}

	int searchIndex(vector<int> &inorder, int left, int right, int val)
	{
		for (int i = left; i <= right; i++)
		{
			if (inorder[i] == val)
			{
				return i;
			}
		}
		return 0;
	}
};
