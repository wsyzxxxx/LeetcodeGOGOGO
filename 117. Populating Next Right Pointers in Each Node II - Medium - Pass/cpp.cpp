/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
private:
    Node * connRight(Node * root, Node * right) {
        if (root == nullptr) {
            return right;
        }
        
        root->next = right;
        Node * next = nullptr;
        while (right) {
            if (right->left || right->right) {
                break;
            }
            right = right->next;
        }
        if (right != nullptr) {
            next = right->left ? right->left : right->right;
        } else {
            next = nullptr;
        }
        next = connRight(root->right, next);
        connRight(root->left, next);
        
        return root;
    }
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
    
        connRight(root, nullptr);
        return root;
    }
};
