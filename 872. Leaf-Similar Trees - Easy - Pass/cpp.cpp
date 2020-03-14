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
    void dfs(TreeNode * root, std::string & str) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            str += root->val;
            return;
        }
        
        dfs(root->left, str);
        dfs(root->right, str);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::string str1, str2;
        dfs(root1, str1);
        dfs(root2, str2);
        
        return str1 == str2;
    }
};
