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
    std::map<int, std::vector<std::pair<int, int> > > mp;
    void traversal(TreeNode * root, int x, int y) {
        if (root == nullptr) {
            return;
        }
        
        mp[x].push_back({y, root->val});
        
        traversal(root->left,  x-1, y+1);
        traversal(root->right, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int> > res;
        mp.clear();
        if (root == nullptr) {
            return res;
        }
        
        traversal(root, 0, 0);
        for (auto & v : mp) {
            std::sort(v.second.begin(), v.second.end());
            std::vector<int> r;
            for (const auto & i : v.second) {
                r.push_back(i.second);
            }
            res.push_back(r);
        }
        
        return res;
    }
};
