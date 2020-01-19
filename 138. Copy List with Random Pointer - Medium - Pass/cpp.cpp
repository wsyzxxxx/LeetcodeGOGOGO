/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    Node * copyList(Node * head) {
        Node * curr = head;
        while (curr != nullptr) {
            Node * next = curr->next;
            Node * newNode = new Node(curr->val);
            newNode->next = next;
            curr->next = newNode;
            curr = next;
        }
        
        return head;
    }
    
    Node * copyPointer(Node * head) {
        Node * curr = head;
        while (curr != nullptr) {
            Node * newNode = curr->next;
            if (curr->random) {
                newNode->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        return head;
    }
    Node * divideList(Node * head) {
        Node * curr = head;
        Node * newHead = curr->next;
        Node * currNew = curr->next;
        while (currNew->next != nullptr) {
            curr->next = currNew->next;
            curr = curr->next;
            currNew->next = curr->next;
            currNew = currNew->next;
        }
        curr->next = nullptr;
        currNew->next = nullptr;
        
        return newHead;
    }
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        
        head = copyList(head);
        head = copyPointer(head);
        Node * newHead = divideList(head);
        
        return newHead;
    }
};
