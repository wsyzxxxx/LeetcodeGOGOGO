/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool match(TreeNode * root, TreeNode * curr) {
        if (root == nullptr && curr == nullptr) {
            return true;
        }
        if (root == nullptr || curr == nullptr) {
            return false;
        }
        //std::cout << root->val << " " << curr->val << std::endl;
        if (root->val != curr->val) {
            return false;
        }
        
        return match(root->left, curr->left) && match(root->right, curr->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return subRoot == nullptr;
        }
        
        if (match(root, subRoot)) {
            return true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};