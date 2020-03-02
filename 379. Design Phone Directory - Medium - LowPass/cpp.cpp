class PhoneDirectory {
private:
    class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int _val): val(_val), next(nullptr) {}
    };
    int maxSize;
    int currSize;
    ListNode * head;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers): maxSize(maxNumbers), currSize(0) {
        ListNode ** curr = &head;
        for (int i = 0; i < maxNumbers; i++) {
            *curr = new ListNode(i);
            curr = &((*curr)->next);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (head == nullptr) {
            return -1;
        }
        int res = head->val;
        ListNode * temp = head;
        head = head->next;
        delete temp;
        
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= maxSize) {
            return false;
        }
        
        ListNode * curr = head;
        while (curr) {
            if (curr->val == number) {
                return true;
            }
            curr = curr->next;
        }
        
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        ListNode * curr = head;
        while (curr) {
            if (curr->val == number) {
                return;
            }
            curr = curr->next;
        }
        
        ListNode * newHead = new ListNode(number);
        newHead->next = head;
        head = newHead;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
