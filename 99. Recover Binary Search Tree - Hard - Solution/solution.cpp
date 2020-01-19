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
    TreeNode * firstNode = nullptr;
    TreeNode * secondNode = nullptr;
    TreeNode * preNode = nullptr;
    void checkTree(TreeNode * root) {
        if (root == nullptr) {
            return;
        }
        
        checkTree(root->left);
        
        if (firstNode == nullptr && preNode != nullptr && preNode->val > root->val) {
            firstNode = preNode;
        }
        
        if (firstNode != nullptr && preNode->val > root->val) {
            secondNode = root;
        }
        
        preNode = root;
        
        checkTree(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        checkTree(root);
        
        std::swap(firstNode->val, secondNode->val);
    }
};
