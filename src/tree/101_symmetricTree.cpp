/*
 * 101. Symmetric Tree
 * */

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymRecursive(root->left, root->right);
                
    }
    
    bool isSymRecursive(TreeNode* rootLeft, TreeNode* rootRight) {
        if (rootLeft!=nullptr && rootRight!=nullptr) {
            if (rootLeft->val==rootRight->val) {
                return isSymRecursive(rootLeft->left, rootRight->right) && isSymRecursive(rootLeft->right, rootRight->left);                
            } else {
                return false;
            }
        }
        if (rootLeft==nullptr && rootRight==nullptr) {
            return true;
        }
        return false;
    }
};
