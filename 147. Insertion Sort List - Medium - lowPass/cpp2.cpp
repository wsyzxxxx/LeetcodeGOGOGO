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
        while (curr) {
            ListNode ** insertPos = &head;
            while (*insertPos != nullptr && (*insertPos)->val < curr->val) {
                insertPos = &((*insertPos)->next);
            }
            ListNode * temp = *insertPos;
            ListNode * next = curr->next;
            *insertPos = curr;
            curr->next = temp;
            curr = next;
        }
        
        return head;
    }
};
