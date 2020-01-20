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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        if (head == nullptr) {
            return res;
        }
        
        ListNode * curr = head;
        while (curr) {
            res = (res << 1) + curr->val;
            curr = curr->next;
        }
        
        return res;
    }
};
