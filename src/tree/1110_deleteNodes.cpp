/*
 * deleteNodes.cpp
 *
 *  Created on: Apr 9, 2022
 *      Author: ganzo
 *      1110. Delete Nodes And Return Forest - Medium
 *
 *
 */

#include <algorithm> // std::sort
#include <iomanip>
#include <iostream> // std::cout
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Definition for a binary tree node.
 */
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
	vector<TreeNode *> treeVector;
	unordered_set<int> s;
	int delNode_recursive(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		if (s.find(root->val) != s.end())
		{
			if (delNode_recursive(root->left))
			{
				root->left = nullptr;
			}
			else
			{
				if (root->left != nullptr)
				{
					treeVector.push_back(root->left);
				}
			}

			if (delNode_recursive(root->right))
			{
				root->right = nullptr;
			}
			else
			{
				if (root->right != nullptr)
				{
					treeVector.push_back(root->right);
				}
			}
			delete root;
			return 1;
		}

		if (delNode_recursive(root->left))
		{
			root->left = nullptr;
		}
		if (delNode_recursive(root->right))
		{
			root->right = nullptr;
		}
		return 0;
	}

  public:
	vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
	{
		for (auto delete_node : to_delete)
		{
			s.insert(delete_node);
		}

		if (root != nullptr)
		{
			if (!delNode_recursive(root))
			{
				treeVector.push_back(root);
			}
		}
		return treeVector;
	}
};

TreeNode *create_tree(vector<int> &input_val)
{
	if (input_val.size() == 0)
	{
		return nullptr;
	}
	TreeNode *tree = new TreeNode(input_val[0]);
	TreeNode *curr_node;
	TreeNode *temp_node;
	curr_node = tree;
	int left_right = 0;
	queue<TreeNode *> treeQueue;

	for (uint32_t i = 1; i < input_val.size(); i++)
	{
		if (input_val.at(i) == 0)
		{
			temp_node = nullptr;
		}
		else
		{
			temp_node = new TreeNode(input_val[i]);
			treeQueue.push(temp_node);
		}

		if (!left_right)
		{
			curr_node->left = temp_node;
			left_right = 1;
		}
		else
		{
			curr_node->right = temp_node;
			left_right = 0;
			if (!treeQueue.empty())
			{
				curr_node = treeQueue.front();
				treeQueue.pop();
			}
		}
	}
	return tree;
}

void printLevelOrder(TreeNode *root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue<TreeNode *> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		TreeNode *node = q.front();
		cout << node->val << " ";
		q.pop();

		/* Enqueue left child */
		if (node->left != NULL)
			q.push(node->left);

		/*Enqueue right child */
		if (node->right != NULL)
			q.push(node->right);
	}
}

int main()
{
	//	vector<int> input_val{1,2,NULL,4,3};
	//	vector<int> delete_val{2,3};

	//	vector<int> input_val{1,2,3,4,5,6,7};
	//	vector<int> delete_val{3,5};

	vector<int> input_val{1, 2, 3, NULL, NULL, NULL, 4};
	vector<int> delete_val{2, 1};

	TreeNode *myTree;
	myTree = create_tree(input_val);

	vector<TreeNode *> myTreeVector;
	Solution sol;
	myTreeVector = sol.delNodes(myTree, delete_val);

	for (auto tree : myTreeVector)
	{
		cout << "[";
		printLevelOrder(tree);
		cout << "]" << endl;
	}

	return 0;
}
