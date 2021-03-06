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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode * curr = root;
        TreeNode * prev = NULL;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        
        return res;
    }
};
