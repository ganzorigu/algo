/*
 * 404. Sum of Left Leaves - Easy
 * */
// Definition for a binary tree node.
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
	int sumOfLeftLeaves(TreeNode *root)
	{

		return sumRecursive(root, false);
	}

	int sumRecursive(TreeNode *root, bool leftLeave)
	{
		if (root == nullptr)
		{
			return 0;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			if (leftLeave)
			{
				return root->val;
			}
			else
			{
				return 0;
			}
		}

		int lhs, rhs;
		lhs = sumRecursive(root->left, true);
		rhs = sumRecursive(root->right, false);

		return lhs + rhs;
	}
};
