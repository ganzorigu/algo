// 235. Lowest Common Ancestor of a Binary Search Tree
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of
// two given nodes in the BST.

// According to the definition of LCA on Wikipedia: â€œThe lowest common
// ancestor is defined between two nodes p and q as the lowest node in T that
// has both p and q as descendants (where we allow a node to be a descendant of
// itself).â€?

// 2 solution to solve

// Solution1: used 2 vectors to store the ancestors until the node is found.
// then compare two vectors to find the lowest ancestor.

// Solution2: Since it is BST. So root is either higher than one node, smaller
// than other node. and vice versa. If one of them found after checking previous
// condition, then return that value.

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
	TreeNode *result;

  public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		recursiveSimple(root, p, q);
		return result;
		//         vector<TreeNode*> leftAncestors;
		//         vector<TreeNode*> rightAncestors;

		//         recursiveTraverse(root, p, leftAncestors);
		//         recursiveTraverse(root, q, rightAncestors);

		//         vector<TreeNode*> *olderNode;
		//         vector<TreeNode*> *youngerNode;

		//         if (leftAncestors.size() > rightAncestors.size()) {
		//             olderNode = &rightAncestors;
		//             youngerNode = &leftAncestors;
		//         } else {
		//             olderNode = &leftAncestors;
		//             youngerNode = &rightAncestors;
		//         }
		//         for (int i=0; i<olderNode->size(); i++) {
		//             for (int j=0; j<youngerNode->size(); j++) {
		//                 if (((*olderNode)[i])->val ==
		//                 ((*youngerNode)[j])->val) {
		//                     return (*olderNode)[i];
		//                 }
		//             }
		//         }

		// if (leftAncestors.size() > rightAncestors.size()) {
		//     for (int i=0; i<rightAncestors.size(); i++) {
		//         for (int j=0; j<leftAncestors.size(); j++) {
		//             if (rightAncestors[i]->val == leftAncestors[j]->val) {
		//                 return rightAncestors[i];
		//             }
		//         }
		//     }
		// } else {
		//     for (int i=0; i<leftAncestors.size(); i++) {
		//         for (int j=0; j<rightAncestors.size(); j++) {
		//             if (rightAncestors[j]->val == leftAncestors[i]->val) {
		//                 return leftAncestors[i];
		//             }
		//         }
		//     }
		// }

		return nullptr;
	}

	void recursiveSimple(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (root == nullptr)
		{
			return;
		}
		if (root->val > p->val && root->val < q->val)
		{
			result = root;
			return;
		}
		else if (root->val < p->val && root->val > q->val)
		{
			result = root;
			return;
		}

		if (root->val == p->val || root->val == q->val)
		{
			result = root;
			return;
		}
		// if (root->val == p->val && (root->val > q->val || root->val <
		// q->val)) {
		//     result = root;
		// }

		recursiveSimple(root->left, p, q);
		if (result)
		{
			return;
		}
		recursiveSimple(root->right, p, q);
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
