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
    bool isSymmetrical(TreeNode * left, TreeNode * right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        
        if (left != NULL && right != NULL) {
            return left->val == right->val &&
                   isSymmetrical(left->left, right->right) &&
                   isSymmetrical(left->right, right->left);
        } else {
            return false;
        }
    }
public:
    bool isSymmetrical(TreeNode* pRoot) {
        return isSymmetrical(pRoot, pRoot);
    }

};
