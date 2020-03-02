/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node * newNode = new Node(insertVal);
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }
        
        Node * curr = head;
        while (curr->next != head && curr->val <= curr->next->val) {
            curr = curr->next;
        }
        
        Node * tempHead = curr->next;
        Node * tempTail = curr;
        curr->next = nullptr;
        if (newNode->val <= tempHead->val || newNode->val >= tempTail->val) {
            tempTail->next = newNode;
            newNode->next = tempHead;
        } else {
            curr = tempHead;
            while (curr->next->val < newNode->val) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            tempTail->next = tempHead;
        }
        
        return newNode;
    }
};
