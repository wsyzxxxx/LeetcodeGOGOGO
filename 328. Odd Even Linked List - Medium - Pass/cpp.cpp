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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode * evenHead = nullptr;
        ListNode * evenTail = nullptr;
        ListNode * curr = head;
        while (curr->next) {
            if (evenHead == nullptr) {
                evenHead = evenTail = curr->next;
            } else {
                evenTail->next = curr->next;
                evenTail = curr->next;
            }
            if (evenTail->next) {
                curr->next = evenTail->next;
                curr = evenTail->next;
            } else {
                break;
            }
            evenTail->next = nullptr;
        }
        
        curr->next = evenHead;
        
        return head;
    }
};
