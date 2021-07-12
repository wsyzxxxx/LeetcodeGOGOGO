/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool validateBST(TreeNode * root, int maxLimit, int minLimit) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val < maxLimit && root->val > minLimit) {
            return validateBST(root->left, root->val, minLimit) && validateBST(root->right, maxLimit, root->val);
        } else {
            return false;
        }
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        std::unordered_map<int, std::pair<int, int>> mp;
        for (int i = 0; i < trees.size(); i++) {
            if (mp.find(trees[i]->val) != mp.end()) {
                mp[trees[i]->val].first = i;
            } else {
                mp[trees[i]->val] = {i, -1};
            }
            if (trees[i]->left) {
                if (mp.find(trees[i]->left->val) == mp.end()) {
                    mp[trees[i]->left->val] = {-1, i};
                } else if (mp[trees[i]->left->val].second != -1) {
                    return nullptr;
                } else {
                    mp[trees[i]->left->val].second = i;
                }
            }
            if (trees[i]->right) {
                if (mp.find(trees[i]->right->val) == mp.end()) {
                    mp[trees[i]->right->val] = {-1, i};
                } else if (mp[trees[i]->right->val].second != -1) {
                    return nullptr;
                } else {
                    mp[trees[i]->right->val].second = i;
                }
            }
        }
        
        for (auto & [a, p] : mp) {
            int k = p.first;
            int v = p.second;
            if (v == -1 || k == -1) {
                continue;
            }
            
            //std::cout << " " << a << " " << k << " " << v <<std::endl;
            if (trees[v]->left && trees[v]->left->val == trees[k]->val) {
                if (trees[k]->right && trees[k]->right->val >= trees[v]->val) {
                    return nullptr;
                }
                trees[v]->left = trees[k];
            } else {
                if (trees[k]->left && trees[k]->left->val <= trees[v]->val) {
                    return nullptr;
                }
                trees[v]->right = trees[k];
            }
        }
        
        TreeNode * root = nullptr;
        for (auto & [_, p] : mp) {
            int k = p.first;
            int v = p.second;
            if (k != -1 && v == -1) {
                if (root == nullptr) {
                    root = trees[k];
                } else {
                    return nullptr;
                }
            }
        }
        
        if (validateBST(root, 10000000, -1)) {
            return root;
        } else {
            return nullptr;
        }
    }
};