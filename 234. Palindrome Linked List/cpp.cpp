/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode * curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }
        
        ListNode * nextNode = head;
        ListNode * lastNode = nullptr;
        int reverseCount = count / 2;
        while (reverseCount > 0) {
            ListNode * temp = nextNode->next;
            nextNode->next = lastNode;
            lastNode = nextNode;
            nextNode = temp;
            reverseCount--;
        }
        
        ListNode * nextCurr = count & 1 ? nextNode->next : nextNode;
        curr = lastNode;
        while (nextCurr != nullptr) {
            if (nextCurr->val != curr->val) {
                return false;
            }
            nextCurr = nextCurr->next;
            curr = curr->next;
        }
        
        return true;
    }
};