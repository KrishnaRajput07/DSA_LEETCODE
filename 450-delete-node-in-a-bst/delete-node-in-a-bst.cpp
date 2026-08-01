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
    TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base Case
    if (root == NULL)
        return NULL;

    // Search the node
    if (key < root->val)
        root->left = deleteNode(root->left, key);

    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    else {
        // Node Found

        // Case 1 : Leaf Node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2 : Only Right Child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3 : Only Left Child
        if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 4 : Two Children
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
    }
};