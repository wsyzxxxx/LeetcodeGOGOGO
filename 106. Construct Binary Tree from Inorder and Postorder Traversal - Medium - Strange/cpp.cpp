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
    std::unordered_map<int, int> mp;

private:
    TreeNode * recons(std::vector<int> & postorder, int inorderPos, int postOrderPos, int len) {
        if (len <= 0) {
            return nullptr;
        }
        TreeNode * root = new TreeNode(postorder[postOrderPos]);
        if (len == 1) {
            return root;
        }
        
        int inPos = mp[postorder[postOrderPos]];
        
        root->left = recons(postorder, inPos-1, postOrderPos-(inorderPos-inPos)-1, len-(inorderPos-inPos)-1);
        root->right = recons(postorder, inorderPos, postOrderPos-1, (inorderPos-inPos));
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }
        
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        return recons(postorder, postorder.size()-1, postorder.size()-1, postorder.size());
    }
};
