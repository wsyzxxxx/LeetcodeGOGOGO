/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    Node * subTreeToDoublyList(Node * root, Node * lastNode) {
        if (root->left) {
            lastNode = subTreeToDoublyList(root->left, lastNode);
        }
        root->left = lastNode;
        if (lastNode) {
            lastNode->right = root;
        }
        lastNode = root;
        if (root->right) {
            lastNode = subTreeToDoublyList(root->right, lastNode);
        }
        
        return lastNode;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return root;
        }
        
        Node * r = subTreeToDoublyList(root, nullptr);
        Node * l = root;
        //Node * r = root;
        while (l->left != nullptr) {
            l = l->left;
        }
        // while (r->right != nullptr) {
        //     r = r->right;
        // }
        
        l->left = r;
        r->right = l;
        
        return l;
    }
};
