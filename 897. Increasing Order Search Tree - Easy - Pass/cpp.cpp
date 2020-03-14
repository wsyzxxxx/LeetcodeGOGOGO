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
    TreeNode * res;
    void constructTree(TreeNode * root, TreeNode * lastNode, TreeNode * nextNode) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr) {
            if (lastNode) {
                lastNode->right = root;
            }
            if (res == nullptr) {
                res = root;
            }
        }
        
        if (root->left) {
            constructTree(root->left, lastNode, root);
        }
        root->left = nullptr;
        if (root->right) {
            constructTree(root->right, root, nextNode);
        } else {
            root->right = nextNode;
        }  
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        res = nullptr;
        
        constructTree(root, nullptr, nullptr);
        
        return res;
    }
};
