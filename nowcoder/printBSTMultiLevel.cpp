/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            std::vector<std::vector<int> > res;
            if (pRoot == NULL) {
                return res;
            }
            
            std::queue<TreeNode *> nodes;
            nodes.push(pRoot);
            int toBePrinted = 1;
            int nextLevel = 0;
            std::vector<int> newLevel;
            while (!nodes.empty()) {
                TreeNode * curr = nodes.front();
                nodes.pop();
                newLevel.push_back(curr->val);
                
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
                }
            }
            
            return res;
        }
    
};
