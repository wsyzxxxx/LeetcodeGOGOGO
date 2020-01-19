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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode * curr = head->next;
        head->next = nullptr;
        while (curr != nullptr) {
            ListNode * next = curr->next;
            curr->next = nullptr;
            ListNode ** pos = &head;
            while (*pos != nullptr && curr->val > (*pos)->val) {
                pos = &((*pos)->next);
            }
            if (*pos != nullptr) {
                curr->next = *pos;
            //    *pos = curr;
            }
            *pos = curr;
            // } else {
            //     curr->next = next;
            // }
            
            curr = next;
        }
        
        return head;
    }
};
