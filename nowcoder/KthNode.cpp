/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    TreeNode * kthNode(TreeNode * root, int & k) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode * temp = kthNode(root->left, k);
        
        if (k < 1) {
            return temp;
        }
        k--;
        if (k == 0) {
            return root;
        } else {
            return kthNode(root->right, k);
        }
        
        return temp;
    }
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL || k <= 0) {
            return NULL;
        }
        
        return kthNode(pRoot, k);
    }
};
