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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > res;
        if (root == nullptr) {
            return res;
        }
        
        std::queue<TreeNode *> q;
        q.push(root);
        int currLevel = 1;
        int nextLevel = 0;
        std::vector<int> level;
        while (!q.empty()) {
            TreeNode * curr = q.front();
            q.pop();
            level.push_back(curr->val);
            
            if (curr->left) {
                q.push(curr->left);
                nextLevel++;
            }
            if (curr->right) {
                q.push(curr->right);
                nextLevel++;
            }
            
            currLevel--;
            if (currLevel == 0) {
                res.push_back(level);
                level.clear();
                currLevel = nextLevel;
                nextLevel = 0;
            }
        }
        
        return res;
    }
};
