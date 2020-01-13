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
    int getHeight(TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        return std::max(left, right) + 1;
    }
    void traversal(std::vector<std::vector<int> > & res, TreeNode * root, int currLevel, int height) {
        if (root == NULL) {
            return;
        }
        
        traversal(res, root->left, currLevel+1, height);
        traversal(res, root->right, currLevel+1, height);
        res[height-1-currLevel].push_back(root->val);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int> > res;
        if (root == nullptr) {
            return res;
        }
        
        int height = getHeight(root);
        
        while (res.size() < height) {
                res.push_back({});
        }
        
        traversal(res, root, 0, height);
        
        return res;
    }
};
