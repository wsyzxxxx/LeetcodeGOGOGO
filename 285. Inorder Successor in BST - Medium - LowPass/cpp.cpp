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
    TreeNode * dst;
    bool found;
    
    void findSuccessor(TreeNode * root, TreeNode * p) {
        if (root == nullptr) {
            return;
        }
        
        findSuccessor(root->left, p);
        if (found) {
            dst = root;
            found = false;
            return;
        }
        
        if (root == p) {
            found = true;
        }
        findSuccessor(root->right, p);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        found = false;
        dst = nullptr;
        
        findSuccessor(root, p);
        
        return dst;
    }
};