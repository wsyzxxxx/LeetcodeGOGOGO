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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode * beforeCurr = head;
        ListNode * curr = head->next;
        head->next = NULL;
        while (curr) {
            ListNode * tempNext = curr->next;
            curr->next = beforeCurr;
            beforeCurr = curr;
            curr = tempNext;
        }
        
        return beforeCurr;
    }
};
