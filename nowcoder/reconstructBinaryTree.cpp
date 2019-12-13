/**
 * Definition for binary tree
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
    TreeNode * reConstructBinaryTree(vector<int> & pre,vector<int> & vin) {
        if (pre.size() <= 0 || vin.size() <= 0 || pre.size() != vin.size()) {
            return NULL;
        }
        
        return constructSubTree(pre, vin, 0, 0, pre.size());
    }
};
