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
    std::vector<TreeNode *> generateSubTrees(int start, int end) {
        std::vector<TreeNode *> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = start; i <= end; i++) {
            std::vector<TreeNode *> leftSub = generateSubTrees(start, i-1);
            std::vector<TreeNode *> rightSub = generateSubTrees(i+1, end);

            for (int j = 0; j < leftSub.size(); j++) {
                for (int k = 0; k < rightSub.size(); k++) {
                    TreeNode * root = new TreeNode(i);
                    root->left = leftSub[j];
                    root->right = rightSub[k];

                    res.push_back(root);
                }
            }
        }

        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode *> res;
        if (n <= 0) {
            return res;
        }

        return generateSubTrees(1, n);
    }
};