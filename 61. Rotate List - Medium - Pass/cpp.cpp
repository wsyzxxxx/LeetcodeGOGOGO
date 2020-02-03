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
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        k = count - k % count;
        
        if (k == 0) {
            return head;
        }
        
        curr = head;
        while (k > 1) {
            curr = curr->next;
            k--;
        }
        
        ListNode * temp = curr->next;
        curr->next = nullptr;
        curr = temp;
        if (curr != nullptr) {
            while (curr && curr->next) {
                curr = curr->next;
            }
            curr->next = head;
            return temp;
        } else {
            return head;
        }
    }
};
