/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode * temp;
private:
    bool isSame(ListNode * first, ListNode ** last) {
        if (first == NULL) {
            return true;
        }
        bool isEqual = isSame(first->next, last) && (first->val == (*last)->val);
        *last = (*last)->next;
        return isEqual;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode ** last = &head;
        return isSame(head, last);
    }
};
