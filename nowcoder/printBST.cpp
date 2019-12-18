/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        std::vector<int> res;
        if (root == NULL) {
            return res;
        }
        
        std::queue<TreeNode *> treeNodeQueue;
        
        treeNodeQueue.push(root);
        
        while (!treeNodeQueue.empty()) {
            TreeNode * curr = treeNodeQueue.front();
            treeNodeQueue.pop();
            res.push_back(curr->val);
            if (curr->left != NULL) {
                treeNodeQueue.push(curr->left);
            }
            if (curr->right != NULL) {
                treeNodeQueue.push(curr->right);
            }
        }
        
        return res;
    }
};
