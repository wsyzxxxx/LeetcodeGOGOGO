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
    ListNode * reverseNNode(ListNode * head, int n) {
        ListNode * prev = nullptr;
        ListNode * curr = head;
        while (curr && n > 1) {
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n--;
        }
        
        head->next = curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m < 1 || n <= m) {
            return head;
        }
        if (m == 1) {
            return reverseNNode(head, n+1);
        }
        
        ListNode * curr = head;
        while (curr && m > 2) {
            curr = curr->next;
            m--;
            n--;
        }
        
        curr->next = reverseNNode(curr->next, n);
        
        return head;
    }
};
