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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        
        ListNode ** curr = &head;
        while ((*curr) != NULL) {
            if ((*curr)->next != NULL && (*curr)->val == (*curr)->next->val) {
                ListNode * dest = (*curr)->next->next;
                while (dest != NULL && dest->val == (*curr)->val) {
                    dest = dest->next;
                }
                *curr = dest;
                
                if (dest == NULL)
                    break;
            } else {
                curr = &((*curr)->next);
            }
        }
        
        return head;
    }
};
