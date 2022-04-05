//  938. Range Sum of BST
//  Given the root node of a binary search tree, return the sum of values 
//  of all nodes with a value in the range [low, high].
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root==nullptr) {
            return 0;    
        }
        int temp=0;
        if (root->val >= low && root->val <= high) {
            temp = temp + root->val;
        }
        
        return temp + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};