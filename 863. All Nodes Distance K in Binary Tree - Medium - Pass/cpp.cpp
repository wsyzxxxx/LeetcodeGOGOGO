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
    int findNodes(TreeNode * root, std::vector<int> & res, TreeNode * target,
                  int K, int currDist) {
        if (root == nullptr) {
            return -1;
        }
        if (currDist > K) {
            return currDist+1;
        }
        if (root == target) {
            currDist = 0;
        }

        if (currDist != -1) {
            findNodes(root->left,  res, target, K, currDist+1);
            findNodes(root->right, res, target, K, currDist+1);
        } else {
            int left = findNodes(root->left, res, target, K, currDist);
            if (left != -1) {
                currDist = left;
                findNodes(root->right, res, target, K, currDist+1);
            } else {
                int right = findNodes(root->right, res, target, K, currDist);
                if (right != -1) {
                    currDist = right;
                    findNodes(root->left, res, target, K, currDist+1);
                }
            }
        }
        if (currDist == K) {
            res.push_back(root->val);
            return currDist+1;
        }
        
        if (currDist != -1) {
            return currDist+1;
        }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == nullptr || K < 0 || target == nullptr) {
            return {};
        }
        
        std::vector<int> res;
        findNodes(root, res, target, K, -1);
        
        return res;
    }
};
