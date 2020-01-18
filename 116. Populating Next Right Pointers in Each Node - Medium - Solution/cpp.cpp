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
// class Solution {
// private:
//     void connRight(Node * root, Node * right) {
//         if (root == nullptr) {
//             return;
//         }
        
//         root->next = right;
//         Node * next = (right == nullptr) ? nullptr : right->left;
//         connRight(root->right, next);
//         connRight(root->left, root->right);
//     }
// public:
//     Node* connect(Node* root) {
//         if (root == nullptr) {
//             return nullptr;
//         }
        
//         connRight(root, nullptr);
        
//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        Node * pre = root;
        Node * curr = nullptr;
        
        while (pre->left) {
            curr = pre;
            while (curr) {
                curr->left->next = curr->right;
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            pre = pre->left;
        }
        
        return root;
    }
};
