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
    int maxSum = INT_MIN;
    int maxPath(TreeNode * root) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;
        maxSum = std::max(maxSum, left+right+root->val);
        
        return std::max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        
        return maxSum;
    }
};
