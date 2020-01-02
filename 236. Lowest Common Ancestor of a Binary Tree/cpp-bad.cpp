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
    TreeNode * findSubTree(TreeNode * root, TreeNode * p, TreeNode * q,
                           bool & hasP, bool & hasQ) {
        if (root == NULL) {
            return NULL;
        }
        
        bool subHasP = false, subHasQ = false;
        TreeNode * left = findSubTree(root->left, p, q, subHasP, subHasQ);
        if (left) {
            return left;
        }
        hasP = subHasP;
        hasQ = subHasQ;
        TreeNode * right = findSubTree(root->right, p, q, subHasP, subHasQ);
        if (right) {
            return right;
        }
        
        hasP = hasP || subHasP || root->val == p->val;
        hasQ = hasQ || subHasQ || root->val == q->val;
        if (hasP && hasQ) {
            return root;
        }
        
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (!p) {
            return q;
        } else if (!q) {
            return p;
        }
        if (p->val == q->val) {
            return p;
        }
        
        bool subHasP = false, subHasQ = false;
        return findSubTree(root, p, q, subHasP, subHasQ);
    }
};
