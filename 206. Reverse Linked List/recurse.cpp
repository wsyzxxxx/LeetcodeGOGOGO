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
    ListNode * reverseCurr(ListNode * beforeCurr, ListNode * curr) {
        if (curr == NULL) {
            return beforeCurr;
        } else {
            ListNode * tempNext = curr->next;
            curr->next = beforeCurr;
            return reverseCurr(curr, tempNext);
        }
    }
    ListNode * reverseList(ListNode * head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode * tempNext = head->next;
        head->next = NULL;
        return reverseCurr(head, tempNext);
    }
};
