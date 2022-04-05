// 102. Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order 
// traversal of its nodes' values. (i.e., from left to right, level by level).

// level order is same as BFS. for iterative solution, use queue;

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <queue>
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
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // recursive solution
        // vector<vector<int>> result;
        // recursiveLevelOrder(root, 0, result);
        // return result;
        //***********************
        
        //iterative solution
        vector<vector<int>> result;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> pairTreeNode;        
        int level;
        q.push(make_pair(root, 0));
        TreeNode* currNode;
        while(!q.empty()) {
            pairTreeNode = q.front();
            currNode = pairTreeNode.first;
            level = pairTreeNode.second;
            q.pop();
            if (pairTreeNode.first) {
                if (result.size() > level) {
                    result[level].push_back(currNode->val);
                } else {
                    result.push_back({currNode->val});
                }
                if (currNode->left) {
                    q.push(make_pair(currNode->left, level+1));
                }
                
                if (currNode->right) {
                    q.push(make_pair(currNode->right, level+1));
                }                
            }
        }
        return result;
    }
    
    void recursiveLevelOrder(TreeNode* root, int level, vector<vector<int>> &result) {
        if (root==nullptr) {
            return;
        } 
        
        if (result.size() > level) {
            // already exist
            result[level].push_back(root->val);
        } else {
            // new vector
            result.push_back({root->val});
        }
        
        recursiveLevelOrder(root->left, level+1, result);
        recursiveLevelOrder(root->right, level+1, result);
        
    }
};