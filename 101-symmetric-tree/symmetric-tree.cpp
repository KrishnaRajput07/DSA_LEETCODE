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
class Solution {
public:
// same like invert tree
     bool helper(TreeNode* left, TreeNode* right) {
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;

        if(left->val != right->val) return false;
        // caling perfectly is imp
        bool a=helper(left->left, right->right); 
        bool b=helper(left->right, right->left);
        return a&&b;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;

        return helper(root->left, root->right);
    }
};