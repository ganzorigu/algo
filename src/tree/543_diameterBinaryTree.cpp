#include <iostream>
// 543. Diameter of Binary Tree, tree easy
// Given a binary tree, you need to compute the length of the diameter of the tree. 
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root. 

 using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    int maxLength = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameterRecursive(root);
        return maxLength;
    }
    
    int diameterRecursive(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        
        int leftNode = 1 + diameterRecursive(root->left);
        int rightNode = 1 + diameterRecursive(root->right);
        int currLength = leftNode+rightNode;
        //cout << "currLength:" << currLength << endl;
        if (currLength > maxLength) {
            maxLength = currLength; 
        }
        return max(leftNode, rightNode);
        
    }
};