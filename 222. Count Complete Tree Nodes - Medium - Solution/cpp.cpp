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
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        TreeNode * curr = root;
        int lheight = 0;
        while (curr != nullptr) {
            curr = curr->left;
            lheight++;
        }
        
        int rheight = 0;
        curr = root;
        while (curr != nullptr) {
            curr = curr->right;
            rheight++;
        }
        
        int res = 1;
        for (int i = 0; i < lheight; i++) {
            res <<= 1;
        }
        if (lheight == rheight) {
            return res - 1;
        }
        
        int start = 0;
        int end = res/2 - 1;
        int base = res/2/2;
        while (start < end) {
            int mid = (start + end + 1) / 2;
            
            curr = root;
            int tbase = base;
            while (tbase) {
                if (mid & tbase) {
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
                
                tbase >>= 1;
            }
            if (curr != nullptr) {
                start = mid;
            } else {
                end = mid - 1;
            }
        }
        
        //std::cout << res/2 << " " << start << std::endl;
        return res/2+ start;
    }
};