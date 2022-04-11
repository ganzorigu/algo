// 617. Merge Two Binary Trees

// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other,
// some nodes of the two trees are overlapped while the others are not.
// You need to merge the two trees into a new binary tree. The merge rule is
// that if two nodes overlap, then sum node values up as the new value of the
// merged node. Otherwise, the NOT null node will be used as the node of the new
// tree.

// Return the merged tree.

// Note: The merging process must start from the root nodes of both trees.

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
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
	{

		if (root1 == nullptr && root2 == nullptr)
		{
			// last node
			return nullptr;
		}
		TreeNode *resTree = new TreeNode();

		int temp = 0;
		if (root1 != nullptr)
		{
			temp += root1->val;
		}
		if (root2 != nullptr)
		{
			temp += root2->val;
		}
		// cout << "new val:" << temp << endl;
		resTree->val = temp;

		if (root1 && root2)
		{
			// cout << "case1" << endl;
			// cout << "root2 val:" << root2->val << endl;
			resTree->left = mergeTrees(root1->left, root2->left);
			resTree->right = mergeTrees(root1->right, root2->right);
		}
		else if (!root1 && root2)
		{
			// cout << "case2" << endl;
			resTree->left = mergeTrees(nullptr, root2->left);
			resTree->right = mergeTrees(nullptr, root2->right);
		}
		else if (root1 && !root2)
		{
			// cout << "case3" << endl;
			resTree->left = mergeTrees(root1->left, nullptr);
			resTree->right = mergeTrees(root1->right, nullptr);
		}
		return resTree;
	}
};
