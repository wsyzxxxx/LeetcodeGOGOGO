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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        
        if (root == NULL) 
            return res;
        
        TreeNode * curr = root;
        do {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            
            curr = curr->right;
        } while (!s.empty() || curr);
        
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        std::stack<TreeNode *> s;
        TreeNode * curr = root;
        while (!s.empty() || curr) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();

            res.push_back(curr->val);
            curr = curr->right;
                
        }
        
        
        return res;
    }
};
