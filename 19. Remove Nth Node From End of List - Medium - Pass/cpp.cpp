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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode * fast = head;
        while (fast && n) {
            fast = fast->next;
            n--;
        }
        
        ListNode ** slow = &head;
        while (fast) {
            slow = &((*slow)->next);
            fast = fast->next;
        }
        
        ListNode * temp = *slow;
        *slow = (*slow)->next;
        delete temp;
        
        return head;
    }
};
