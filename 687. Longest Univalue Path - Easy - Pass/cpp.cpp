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
    int maxSum;
    int longest(TreeNode * root, int currNum) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = longest(root->left, root->val);
        int right = longest(root->right, root->val);
        
        int sum = left + right;
        if (sum > maxSum) {
            maxSum = sum;
        }
        
        if (currNum == root->val) {
            return std::max(left, right) + 1;
        } else {
            return 0;
        }
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        maxSum = 0;
        int res = longest(root, root->val);
        return maxSum;
    }
};
