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
    int maxD;
    int treeDepth(TreeNode * root) {
        if (root == NULL) {
            return 0;
        } else {
            int left = treeDepth(root->left);
            int right = treeDepth(root->right);
            maxD = max(maxD, left+right);
            return max(left+1, right+1);
        }
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxD = 0;
        treeDepth(root);
        return maxD;
    }
};
