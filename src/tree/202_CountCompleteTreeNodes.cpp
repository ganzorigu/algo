/*
 * 202. Count Complete Tree Nodes
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
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
    int countNodes(TreeNode* root) {
        
//         int maxNodes = pow(2,depth+1);
//         int maxLeafNodes = maxNodes/2;
//         int maxNodes = maxNodes-1;                
//         int currNodes = 0;
        
        
//         while(currNodes < maxNodes) {
            
            
//         }
        
//         int findDepth(TreeNode* root) {
//             int depth = 0;
//             while(root->left!=nullptr) {
//                 root = root->left;
//                 depth++;
//             }
//             return depth;
//         }
        
        if (root==nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);                
    }
    
    
    
    
    // pair<int, int> rightMostLeaf(TreeNode* root, int height, int ) {
    //     if (root->right!=nullptr) {
    //         rightMostLeaft(root->right, )
    //     }
    // }
    
};
