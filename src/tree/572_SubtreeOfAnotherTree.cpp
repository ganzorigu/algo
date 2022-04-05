//  572. Subtree of Another Tree
//  Tree easy
//  Given two non-empty binary trees s and t, check whether tree t has exactly the same 
//  structure and node values with a subtree of s.
//  A subtree of s is a tree consists of a node in s and all of this node's descendants. 
//  The tree s could also be considered as a subtree of itself.
 
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) {
            return false;
        }
        if (s->val == t->val) {
            // if first value is same, check if subtree exist
            // cout << "root is found at:" << s->val << endl;
            if (isSubRecursive(s, t)) {
                return true;
            }
            // if not found keep searching till the last node;
        }
        if (isSubtree(s->left, t)) {
            return true;
        }
        if (isSubtree(s->right, t)) {
            return true;
        }
        return false;
    }
    
    bool isSubRecursive(TreeNode* s, TreeNode* t) {
        if (s == nullptr || t == nullptr) {
            if (s == nullptr && t == nullptr) {
                return true;
            }
            return false;
        }
        // cout << "left val:" <<s->val << "right val: " << t->val << endl;
        bool left, right;
        if (s->val == t->val) {
            left = isSubRecursive(s->left, t->left);
            if (!left) return false;
            right = isSubRecursive(s->right, t->right);
            if (!right) return false;     
            return true;
        }
        return false;
    }
};