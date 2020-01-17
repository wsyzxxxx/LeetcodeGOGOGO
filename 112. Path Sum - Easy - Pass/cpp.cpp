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
    bool hasPathSum(TreeNode * root, int sum, int currSum) {
        if (root == nullptr) {
            return false;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return currSum + root->val == sum;
        }
        
        return hasPathSum(root->left, sum, currSum + root->val) ||
               hasPathSum(root->right, sum, currSum + root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root, sum, 0);
    }
};
