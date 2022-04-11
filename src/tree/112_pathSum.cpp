// 112. Path Sum

//  Given the root of a binary tree and an integer targetSum,
//  return true if the tree has a root-to-leaf path such that adding up
//  all the values along the path equals targetSum.

// A leaf is a node with no children.

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
	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (root == nullptr)
		{
			return false;
		}
		return doesPathExist(root, targetSum, 0);
	}

	bool doesPathExist(TreeNode *root, int targetSum, int currSum)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			// this is leaf node
			return currSum + root->val == targetSum;
		}

		if (root->left != nullptr &&
			doesPathExist(root->left, targetSum, currSum + root->val))
		{
			return true;
		}

		if (root->right != nullptr &&
			doesPathExist(root->right, targetSum, currSum + root->val))
		{
			return true;
		}

		return false;
	}
};
