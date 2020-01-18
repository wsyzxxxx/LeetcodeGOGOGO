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
    void checkSum(std::vector<std::vector<int> > & res, 
                  TreeNode * root, int currSum, int sum, std::vector<int> & currPath) {
        if (root == nullptr) {
            return;
        }
        
        currPath.push_back(root->val);
        currSum += root->val;
        if (root->left == nullptr && root->right == nullptr && currSum == sum) {
            res.push_back(currPath);
        } else {
            checkSum(res, root->left, currSum, sum, currPath);
            checkSum(res, root->right, currSum, sum, currPath);
        }
        currPath.pop_back();
        currSum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int> > res;
        if (root == nullptr) {
            return res;
        }
        
        std::vector<int> currPath;
        checkSum(res, root, 0, sum, currPath);
        
        return res;
    }
};
