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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode * l1 = nullptr;
        ListNode * l1Head = nullptr;
        ListNode * l2 = nullptr;
        ListNode * l2Head = nullptr;
        ListNode * curr = head;
        while (curr) {
            if (curr->val < x) {
                if (l1Head == nullptr) {
                    l1 = l1Head = curr;
                } else {
                    l1->next = curr;
                    l1 = l1->next;
                }
            } else {
                if (l2Head == nullptr) {
                    l2 = l2Head = curr;
                } else {
                    l2->next = curr;
                    l2 = l2->next;
                }
            }
            curr = curr->next;
        }
        if (l1Head) {
            l1->next = l2Head;
            if (l2Head) {
                l2->next = nullptr;
            }
            return l1Head;
        } else {
            return l2Head;
        }
    }
};
