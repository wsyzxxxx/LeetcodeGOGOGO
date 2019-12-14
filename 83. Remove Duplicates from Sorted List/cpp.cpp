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
        ListNode * curr = head;
        while (curr) {
            while (curr->next && curr->next->val == curr->val) {
                ListNode * temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            curr = curr->next;
        }
        
        return head;
    }
};
