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
    int sumOfSubTree(TreeNode * root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        
        sum = (sum << 1) + root->val;
        if (root->left || root->right) {
            return sumOfSubTree(root->left, sum) + sumOfSubTree(root->right, sum);
        } else {
            return sum;
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumOfSubTree(root, 0);
    }
};
