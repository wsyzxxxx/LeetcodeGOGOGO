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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       std::vector<std::vector<int> > res;
        if (root == nullptr) {
            return res;
        }

        std::queue<TreeNode *> nodes;
        nodes.push(root);
        int toBePrinted = 1;
        int nextLevel = 0;
        bool reverseOrder = false;
        std::vector<int> newLevel;
        while (!nodes.empty()) {
            TreeNode * curr = nodes.front();
            nodes.pop();
            if (reverseOrder) {
                newLevel.insert(newLevel.begin(), curr->val);
            } else {
                newLevel.push_back(curr->val);
            }

            if (curr->left) {
                nodes.push(curr->left);
                nextLevel++;
            }

            if (curr->right) {
                nodes.push(curr->right);
                nextLevel++;
            }

            toBePrinted--;
            if (toBePrinted == 0) {
                res.push_back(newLevel);
                newLevel.clear();
                toBePrinted = nextLevel;
                nextLevel = 0;
                reverseOrder = !reverseOrder;
            }
        }

        return res; 
    }
};
