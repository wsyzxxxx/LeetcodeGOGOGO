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
    std::vector<int> res;
    bool flip(TreeNode * root, vector<int>& voyage, int & i) {
        if (root == nullptr) {
            return true;
        }
        if (i == voyage.size()) {
            return true;
        }
        if (root->val != voyage[i]) {
            return false;
        }
        i++;
        if (i < voyage.size() && root->right && root->right->val == voyage[i] && 
           (root->left && root->left->val != voyage[i])) {
            res.push_back(root->val);
            std::swap(root->right, root->left);
        }
        
        return flip(root->left, voyage, i) && flip(root->right, voyage, i);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        res.clear();
        if (root == nullptr || voyage.empty()) {
            return {-1};
        }
        
        int i = 0;
        if (flip(root, voyage, i)) {
            return res;
        } else {
            return {-1};
        }
    }
};
