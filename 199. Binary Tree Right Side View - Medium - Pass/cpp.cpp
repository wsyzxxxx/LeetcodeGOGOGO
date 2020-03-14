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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        
        if (root == nullptr) {
            return res;
        }
        
        std::queue<std::pair<TreeNode *, int> > q;
        q.push(std::make_pair(root, 0));
        while (!q.empty()) {
            TreeNode * currNode = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            
            if (currLevel == res.size()) {
                res.push_back(currNode->val);
            }
            
            if (currNode->right) {
                q.push(std::make_pair(currNode->right, currLevel+1));
            }
            
            if (currNode->left) {
                q.push(std::make_pair(currNode->left, currLevel+1));
            }
        }
        
        return res;
    }
};
