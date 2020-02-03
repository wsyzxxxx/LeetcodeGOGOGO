/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k < 2) {
            return head;
        }
        
        ListNode * curr = head;
        int count = k;
        while (curr && count) {
            curr = curr->next;
            count--;
        }
        if (count > 0) {
            return head;
        }
        
        curr = head;
        count = k;
        ListNode * prev = nullptr;
        while (count > 0) {
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
