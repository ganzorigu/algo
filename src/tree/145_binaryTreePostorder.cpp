// 145. Binary Tree Postorder Traversal
// Given the root of a binary tree, return the postorder traversal of its nodes'
// values.

// postorder traversal is left, right, root.
// recursive solution is easy.
// iterative solution is bit hard. 1. convert to preorder traversal but (root,
// right, left) way to vector.
// 2. then reverse the vector

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

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
	vector<int> result;

  public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		// recursivePostorder(root);
		// return result;

		// iteratively
		stack<TreeNode *> st;

		TreeNode *currNode = root;
		while (currNode || !st.empty())
		{
			if (currNode)
			{
				st.push(currNode);
				result.push_back(currNode->val);
				currNode = currNode->right;
			}
			else
			{
				currNode = st.top();
				st.pop();
				currNode = currNode->left;
			}
		}

		reverse(result.begin(), result.end());
		return result;
	}

	void recursivePostorder(TreeNode *root)
	{
		if (root == nullptr)
		{
			return;
		}

		if (root->left)
		{
			recursivePostorder(root->left);
		}
		if (root->right)
		{
			recursivePostorder(root->right);
		}
		result.push_back(root->val);
	}
};
