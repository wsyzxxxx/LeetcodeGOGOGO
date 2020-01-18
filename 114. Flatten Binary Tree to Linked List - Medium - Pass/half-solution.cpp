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
    TreeNode * flattenSubTree(TreeNode * root, TreeNode * nextNode) {
        if (root == NULL) {
            return nextNode;
        }
        root->right = flattenSubTree(root->right, nextNode);
        root->right = flattenSubTree(root->left, root->right);
        root->left = NULL;
        
        return root;
    }
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        flattenSubTree(root, NULL);
    }
};
