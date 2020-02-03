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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k < 1) {
            return head;
        }
        
        ListNode * curr = head;
        int count = 1;
        while (curr->next) {
            count++;
            curr = curr->next;
        }
        
        k = count - k % count;
        
        curr->next = head;
        while (k) {
            curr = curr->next;
            k--;
        }
        ListNode * res = curr->next;
        curr->next = nullptr;
        
        return res;
    }
};
