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
    ListNode * merge(ListNode * l1, ListNode * l2) {
        ListNode * head = nullptr;
        ListNode ** curr = &head;
        
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    *curr = l1;
                    l1 = l1->next;
                } else {
                    *curr = l2;
                    l2 = l2->next;
                }
                curr = &((*curr)->next);
            } else if (l1) {
                *curr = l1;
                break;
            } else {
                *curr = l2;
                break;
            }
        }
        
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = nullptr;
        //std::cout << "finish" << std::endl;
        ListNode * l1 = sortList(head);
        ListNode * l2 = sortList(fast);
        
        return merge(l1, l2);
    }
};
