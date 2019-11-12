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
                //ListNode * dest = (*curr)->next->next;
                int val = (*curr)->val;
                while (*curr != NULL && (*curr)->val == val) {
                    *curr = (*curr)->next;
                }
            } else {
                curr = &((*curr)->next);
            }
        }
        
        return head;
    }
};
