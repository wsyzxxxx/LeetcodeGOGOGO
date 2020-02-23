/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode * removeSubTree(TreeNode * root) {
        if (root == nullptr) {
            return root;
        }
        root->left = removeSubTree(root->left);
        root->right = removeSubTree(root->right);
        
        if (root->left == nullptr && root->right == nullptr && root->val != 1) {
            return nullptr;
        }
        
        return root;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return removeSubTree(root);
    }
};
