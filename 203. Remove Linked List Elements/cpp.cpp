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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode ** curr = &head;
        while (*curr) {
            if ((*curr)->val == val) {
                *curr = (*curr)->next;
                continue;
            }
            curr = &((*curr)->next);
        }
        
        return head;
    }
};
