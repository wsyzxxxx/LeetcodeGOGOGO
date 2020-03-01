/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
private:
    Node * flatten(Node * curr, Node * lastNode) {
        curr->prev = lastNode;
        if (lastNode) {
            lastNode->next = curr;
        }
        while (curr) {
            if (curr->child) {
                Node * temp = curr->next;
                Node * childNext = flatten(curr->child, curr);
                curr->child = nullptr;
                childNext->next = temp;
                if (temp) {
                    temp->prev = childNext;
                }
                curr = childNext;
            }
            if (curr->next == nullptr) {
                return curr;
            }
            curr = curr->next;
        }
        
        return curr;
    }
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        
        flatten(head, nullptr);
        
        return head;
    }
};
