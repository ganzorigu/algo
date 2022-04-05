/*
 * 270. Closest Binary Search Tree Value - Easy
 * */
#include <iostream>
#include <cfloat>
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
    pair<double, int> minPair = make_pair(DBL_MAX, 0);
public:
    int closestValue(TreeNode* root, double target) {
        if (root==nullptr) {
            return 0;
        }    
        double temp = abs((double)root->val - target);
        if (minPair.first > temp) {
            minPair.first = temp;
            minPair.second = root->val;
        }
        closestValue(root->left, target);
        closestValue(root->right, target);
        return minPair.second;
    }
};
