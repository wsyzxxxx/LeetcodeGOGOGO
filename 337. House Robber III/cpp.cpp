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
    int findMaxInSubTree(TreeNode * root, int & pre) {
        if (root == NULL) {
            pre = 0;
            return 0;
        }

        int lPre;
        int rPre;
        pre = findMaxInSubTree(root->left, lPre) + findMaxInSubTree(root->right, rPre);

        return std::max(lPre + rPre + root->val, pre);
    }
public:
    int rob(TreeNode* root) {
        int pre;
        return findMaxInSubTree(root, pre);
    }
};