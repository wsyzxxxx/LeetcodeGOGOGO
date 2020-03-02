/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int plusInList(ListNode * curr) {
        if (curr == nullptr) {
            return 1;
        }
        
        int carry = plusInList(curr->next);
        if (carry + curr->val >= 10) {
            curr->val = (carry + curr->val) - 10;
            return 1;
        } else {
            curr->val = (carry + curr->val);
            return 0;
        }
    }
public:
    ListNode* plusOne(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        int carry = plusInList(head->next);
        if (carry + head->val >= 10) {
            head->val = (carry + head->val) - 10;
            ListNode * newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        } else {
            head->val = carry + head->val;
            return head;
        }
    }
};
