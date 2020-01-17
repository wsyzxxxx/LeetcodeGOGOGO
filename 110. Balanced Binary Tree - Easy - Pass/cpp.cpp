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
    bool isBalanced(TreeNode * root, int & height) {
        if (root == nullptr) {
            height = 0;
            return true;
        }
        
        int left, right;
        if (isBalanced(root->left, left) && isBalanced(root->right, right)) {
            height = std::max(left, right) + 1;
            return std::max(left, right) - std::min(left, right) < 2;
        }
        
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced(root, height);
    }
};
