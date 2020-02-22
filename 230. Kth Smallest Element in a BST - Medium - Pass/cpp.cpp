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
    int findElement(TreeNode * root, int & k) {
        if (k <= 0 || root == nullptr) {
            return 0;
        }
        
        int left = findElement(root->left, k);

        if (k == 0) {
            return left;
        }
        
        k--;
        if (k == 0) {
            return root->val;
        }
        
        return findElement(root->right, k);
            
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr || k <= 0) {
            return 0;
        }
        
        return findElement(root, k);
    }
};
