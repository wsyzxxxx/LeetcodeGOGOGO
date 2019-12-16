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
    int currNodeSum(TreeNode * root, int preSum, int target) {
        if (root == NULL) {
            return 0;
        }
        int currentSum = preSum + root->val;
        return (currentSum == target) +
            currNodeSum(root->left, currentSum, target) +
            currNodeSum(root->right, currentSum, target);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        return currNodeSum(root, 0, sum) +
            pathSum(root->left, sum) +
            pathSum(root->right, sum);
    }
};
