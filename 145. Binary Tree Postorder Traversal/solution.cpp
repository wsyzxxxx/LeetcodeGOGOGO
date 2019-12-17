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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root == NULL) {
            return res;
        }
        
        std::stack<TreeNode *> nodeStack;
        TreeNode * curr = root;
        while (!nodeStack.empty() || curr != NULL) {
            if (curr != NULL) {
                nodeStack.push(curr);
                res.insert(res.begin(), curr->val);
                curr = curr->right;
            } else {
                curr = nodeStack.top()->left;
                nodeStack.pop();
            }
        }
        
        return res;
    }
};
