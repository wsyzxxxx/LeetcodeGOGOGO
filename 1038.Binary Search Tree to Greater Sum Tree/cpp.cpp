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
    stack<TreeNode*> nodeStack;
public:
    void pushToStack(TreeNode* node) {
        if (node) {
            pushToStack(node->left);
            nodeStack.push(node);
            pushToStack(node->right);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return root;
        }
        pushToStack(root);
        
        int sum = 0;
        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            sum += node->val;
            node->val = sum;
            nodeStack.pop();
        }
        
        return root;
    }
};
