class MyLinkedList {
private:
    class ListNode {
    public:
        int val;
        ListNode * next;
        ListNode(int _val) : val(_val), next(nullptr) {}
    };
    int size = 0;
    ListNode * head = nullptr;
    ListNode * tail = nullptr;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        
        ListNode * curr = head;
        while (curr && index) {
            index--;
            curr = curr->next;
        }
        
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode * newNode = new ListNode(val);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode * newNode = new ListNode(val);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        
        ListNode ** curr = &head;
        while (curr && index) {
            index--;
            curr = &((*curr)->next);
        }
        
        ListNode * newNode = new ListNode(val);
        newNode->next = *curr;
        *curr = newNode;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        
        if (index == 0) {
            ListNode * temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        ListNode * curr = head;
        while (curr && index > 1) {
            index--;
            curr = curr->next;
        }
        
        if (curr->next == tail) {
            delete tail;
            curr->next = nullptr;
            tail = curr;
        } else {
            ListNode * temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
