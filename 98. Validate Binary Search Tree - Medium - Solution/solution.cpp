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
    bool isValidBST(TreeNode * root, TreeNode * low, TreeNode * high) {
        if (root != nullptr) {
            if ((low && root->val <= low->val) || (high && root->val >= high->val)) {
                return false;
            }
            
            return isValidBST(root->left, low, root) &&
                   isValidBST(root->right, root, high);
        }
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};
