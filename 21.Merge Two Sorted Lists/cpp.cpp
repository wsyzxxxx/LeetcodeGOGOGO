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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL;
        ListNode ** current = &head;
        while (l1 || l2) {
            if (l1 && l2) {
                bool which = l1->val < l2->val;
                *current = which ? l1 : l2;
                l1 = which ? l1->next : l1;
                l2 = which ? l2 : l2->next;
            } else if (l1) {
                *current = l1;
                break;
            } else {
                *current = l2;
                break;
            }
            current = &((*current)->next);
        }
        
        return head;
    }
};
