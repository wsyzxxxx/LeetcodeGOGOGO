/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxSum;
    
    int findMaxPath(TreeNode * root) {
        if (root == nullptr) {
            return -1001;
        }
        
        int left = findMaxPath(root->left);
        int right = findMaxPath(root->right);
        
        maxSum = std::max(maxSum, std::max(left+right+root->val, std::max(left, right)));
        //std::cout << root->val << " " << maxSum << std::endl;
        return std::max(root->val, std::max(left+root->val, right+root->val));
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        maxSum = root->val;
        return std::max(findMaxPath(root), maxSum);
    }
};