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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        
        std::stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int curr = 0;
        ListNode * newHead = nullptr;
        while (!s1.empty() || !s2.empty() || curr) {
            if (!s1.empty()) {
                curr += s1.top();
                s1.pop();
            }
            
            if (!s2.empty()) {
                curr += s2.top();
                s2.pop();
            }
            
            ListNode * currNode = new ListNode(curr % 10);
            if (newHead) {
                currNode->next = newHead;
                newHead = currNode;
            } else {
                newHead = currNode;
            }
            
            curr = curr < 10 ? 0 : 1;
        }
        
        return newHead;
    }
};
