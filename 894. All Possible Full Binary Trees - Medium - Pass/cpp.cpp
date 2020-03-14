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
    
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) {
            return {};
        }
        if (N == 1) {
            return {new TreeNode(0)};
        }
        
        std::vector<TreeNode *> res;
        
        for (int i = 1; i < N; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-1-i);
            
            for (const auto & i : left) {
                for (const auto & j : right) {
                    TreeNode * root = new TreeNode(0);
                    root->left = i;
                    root->right = j;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
