// 94. Binary Tree Inorder Traversal
// Given the root of a binary tree, return the inorder traversal of its nodes'
// values.

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
	vector<int> inorderTraversal(TreeNode *root)
	{
		// recursive
		// vector<int> result;
		// recursiveInorder(root, result);
		// return result;

		// iterative
		vector<int> result;
		stack<TreeNode *> st;
		TreeNode *tempNode;
		TreeNode *currNode = root;
		while (currNode || !st.empty())
		{
			if (currNode)
			{
				st.push(currNode);
				currNode = currNode->left;
			}
			else
			{
				tempNode = st.top();
				result.push_back(tempNode->val);
				st.pop();
				currNode = tempNode->right;
			}
		}
		return result;
	}

	void recursiveInorder(TreeNode *root, vector<int> &res)
	{
		if (root == nullptr)
		{
			return;
		}

		recursiveInorder(root->left, res);
		res.push_back(root->val);
		recursiveInorder(root->right, res);
	}
};
