class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * nonNine = dummyHead;
        
        while (head) {
            if (head->val != 9) {
                nonNine = head;
            }
            head = head->next;
        }
        
        nonNine->val++;
        nonNine = nonNine->next;
        
        while (nonNine) {
            nonNine->val = 0;
            nonNine = nonNine->next;
        }
        
        return dummyHead->val == 1 ? dummyHead : dummyHead->next;
    }
};
