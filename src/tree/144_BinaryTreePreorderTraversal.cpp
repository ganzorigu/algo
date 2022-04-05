// 144. Binary Tree Preorder Traversal
// Given the root of a binary tree, return the preorder traversal of its nodes' values.

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>

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
    vector<int> result;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        // recursivePreorder(root);
        // return result;
        stack<TreeNode*> st;
        TreeNode* currNode = root;
        while(currNode || !st.empty()) {            
            if (currNode) {
                st.push(currNode);
                result.push_back(currNode->val);
                currNode = currNode->left;
            } else {
                currNode = st.top();
                st.pop();
                currNode = currNode->right;
            }                        
        }
        return result;
        
    }
    
    void recursivePreorder(TreeNode* root) {
        if (root==nullptr) {
            return;
        }
        
        result.push_back(root->val);
        if (root->left) {
            recursivePreorder(root->left);    
        }
        if (root->right) {
            recursivePreorder(root->right);    
        }                              
    }
    
};
