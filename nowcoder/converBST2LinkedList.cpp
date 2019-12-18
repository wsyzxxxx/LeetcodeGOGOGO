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
    TreeNode* convert(TreeNode* prevNode, TreeNode* curr) {
        if (curr == NULL) {
            return prevNode;
        }
        
        prevNode = convert(prevNode, curr->left);
        curr->left = prevNode;
        if (prevNode != NULL) {
            prevNode->right = curr;
        }
        
        if (curr->right == NULL) {
            return curr;
        } else {
            return convert(curr, curr->right);
        }
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) {
            return NULL;
        }
        
        convert(NULL, pRootOfTree);
        while (pRootOfTree->left != NULL) {
            pRootOfTree = pRootOfTree->left;
        }
        
        return pRootOfTree;
    }
};
