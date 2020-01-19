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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m <= 0 || n <= 0 || n <= m) {
            return head;
        }
        
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * curr = dummy;
        while (curr != nullptr && m > 1) {
            curr = curr->next;
            m--;
            n--;
        }
        
        ListNode * prevHead = curr;
        ListNode * prev = curr;
        curr = curr->next;
        for (int i = 0; i <= n-m; i++) {
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prevHead->next->next = curr;
        prevHead->next = prev;
        
        ListNode * res = dummy->next;
        delete dummy;
        return res;
    }
};
