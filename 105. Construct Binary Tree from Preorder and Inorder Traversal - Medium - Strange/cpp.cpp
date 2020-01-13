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
    TreeNode * constructSubTree(vector<int> & pre,vector<int> & vin,
                                int prePos, int inPos, int currLength) {
        if (currLength <= 0) {
            return NULL;
        }

        TreeNode * node = new TreeNode(pre[prePos]);
        int i = inPos;
        while (vin[i] != pre[prePos]) {
            i++;
        }
        node->left = constructSubTree(pre,
                                      vin,
                                      prePos+1,
                                      inPos,
                                      i-inPos);
        node->right = constructSubTree(pre,
                                       vin,
                                       prePos+i-inPos+1,
                                       i+1,
                                       inPos+currLength-i-1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int> & preorder, vector<int> & inorder) {
        if (preorder.size() <= 0 || inorder.size() <= 0 || preorder.size() != inorder.size()) {
            return NULL;
        }
        return constructSubTree(preorder, inorder, 0, 0, preorder.size());
    }
};
