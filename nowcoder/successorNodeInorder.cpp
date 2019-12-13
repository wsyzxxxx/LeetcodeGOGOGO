/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == NULL) {
            return NULL;
        }
        
        TreeLinkNode * node;
        if (pNode->right != NULL) {
            node = pNode->right;
            while (node->left != NULL) {
                node = node->left;
            }
        } else {
            node = pNode;
            while (node->next != NULL && node == node->next->right) {
                node = node->next;
            }
            node = node->next;
        }
        
        return node;
        
        
    }
};
