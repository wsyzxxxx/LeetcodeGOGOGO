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
private:
    bool checkSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) {
            return true;
        } else if (pRoot1 == NULL) {
            return false;
        }
        
        return (pRoot1->val == pRoot2->val) &&
                checkSubTree(pRoot1->left, pRoot2->left) &&
                checkSubTree(pRoot1->right, pRoot2->right);
    }
    bool findRootAndCheck(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == NULL) {
            return false;
        }
        if (pRoot1->val == pRoot2->val) {
            if (checkSubTree(pRoot1, pRoot2)) {
                return true;
            }
        }
        return findRootAndCheck(pRoot1->left, pRoot2) ||
               findRootAndCheck(pRoot1->right, pRoot2);
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == NULL || pRoot2 == NULL) {
            return false;
        }
        
        return findRootAndCheck(pRoot1, pRoot2);
    }
};
