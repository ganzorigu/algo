// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder 
// traversal of a binary tree and inorder is the inorder traversal of the same tree, 
// construct and return the binary tree.

// Reference: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
#include <iostream>
#include <unordered_map>
#include <vector>
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
    //int index;
    unordered_map<int,int> umap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //index = 0;
        for (int i=0; i<inorder.size(); i++) {
            umap[inorder[i]] = i;
        }
        return recursiveBuildTree(preorder, inorder, 0, 0, preorder.size()-1);
    }
    
    TreeNode* recursiveBuildTree(vector<int>& preorder, vector<int>& inorder, int start, int left, int right) {        
        
        if (left>right) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[start]);
        //base case
        if (left==right) {
            // there is no child node
            return root;
        }        
        
        int foundIndex = umap[root->val];//searchIndex(inorder, left, right, root->val);
        root->left = recursiveBuildTree(preorder, inorder, start+1, left, foundIndex-1);
        root->right = recursiveBuildTree(preorder, inorder, start + foundIndex - left + 1, foundIndex+1, right);
        return root;
    }
    
    int searchIndex(vector<int>& arr, int left, int right, int val) {
        
        for (int i=left; i<=right; i++) {
            if (arr[i]==val) {
                return i;
            }
        }
        return 0;
    }
};