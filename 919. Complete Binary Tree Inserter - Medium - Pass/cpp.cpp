/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    std::vector<TreeNode *> treeList;
public:
    CBTInserter(TreeNode* root) {
        treeList.clear();
        treeList.push_back(root);
        for (int i = 0; i < treeList.size() && treeList[i] != nullptr; i++) {
            if (treeList[i]->left) {
                treeList.push_back(treeList[i]->left);
            }
            if (treeList[i]->right) {
                treeList.push_back(treeList[i]->right);
            }
        }
    }
    
    int insert(int v) {
        int index = treeList.size();
        if (treeList[0] == nullptr) {
            treeList[0] = new TreeNode(v);
            return 0;
        }
        
        treeList.push_back(new TreeNode(v));
        int parent = (index-1) / 2;
        if (index == parent * 2 + 1) {
            treeList[parent]->left = treeList.back();
        } else {
            treeList[parent]->right = treeList.back();
        }
        return treeList[parent]->val;
    }
    
    TreeNode* get_root() {
        return treeList[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
