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
    int preIndex, posIndex;

private:
    TreeNode * recons(std::vector<int> & pre, std::vector<int> & post) {
        TreeNode * root = new TreeNode(pre[preIndex++]);
        if (root->val != post[posIndex]) {
            root->left = recons(pre, post);
        }
        if (root->val != post[posIndex]) {
            root->right = recons(pre, post);
        }
        posIndex++;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty() || pre.size() != post.size()) {
            return NULL;
        }
        
        preIndex = 0;
        posIndex = 0;
        return recons(pre, post);
    }
};


