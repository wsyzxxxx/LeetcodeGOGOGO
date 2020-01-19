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
    void findPaths(TreeNode * root, std::vector<std::string> & res,
                   std::string currStr) {
        if (root == nullptr) {
            return;
        }
        
        std::ostringstream oss;
        if (!currStr.empty()) {
            oss << "->";
        }
        oss << root->val;
        currStr += oss.str();
        if (root->left || root->right) {
            findPaths(root->left, res, currStr);
            findPaths(root->right, res, currStr);
        } else {
            res.push_back(currStr);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        if (root == nullptr) {
            return res;
        }
        
        std::string currStr = "";
        findPaths(root, res, currStr);
        
        return res;
    }
};
