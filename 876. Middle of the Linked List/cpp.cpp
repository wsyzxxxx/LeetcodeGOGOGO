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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode * curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        
        curr = head;
        size /= 2;
        while (size--) {
            curr = curr->next;
        }
        return curr;
    }
};
