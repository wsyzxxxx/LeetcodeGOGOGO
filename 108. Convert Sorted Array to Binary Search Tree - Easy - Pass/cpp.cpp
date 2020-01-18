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
    TreeNode * constructTree(std::vector<int> & nums, int start, int end) {
        if (start == end) {
            return nullptr;
        }
        
        int mid = (start + end) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = constructTree(nums, start, mid);
        root->right = constructTree(nums, mid+1, end);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size());
    }
};
