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
    double maxAvg;
    int findMaxAvg(TreeNode * root, int & nodeNum) {
        if (root == nullptr) {
            return 0;
        }
        
        int subTreeNodeNum = 1;
        int currSum = root->val;
        currSum += findMaxAvg(root->left, subTreeNodeNum);
        currSum += findMaxAvg(root->right, subTreeNodeNum);
        
        maxAvg = std::max((double)currSum / subTreeNodeNum, maxAvg);
        nodeNum += subTreeNodeNum;
        
        return currSum;
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        maxAvg = 0;
        int nodeNum = 0;
        
        return std::max((double)findMaxAvg(root, nodeNum) / nodeNum, maxAvg);
    }
};
