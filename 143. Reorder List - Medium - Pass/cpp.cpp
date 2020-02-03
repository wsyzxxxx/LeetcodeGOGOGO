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
    ListNode * reverseList(ListNode * head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        ListNode * curr = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode * mergeList(ListNode * l1, ListNode * l2) {
        ListNode * dummyNode = new ListNode(0);
        ListNode * curr = dummyNode;
        
        while (l1 || l2) {
            if (l1 && l2) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            } else if (l1) {
                curr->next = l1;
                break;
            } else {
                curr->next = l2;
                break;
            }
        }
        
        ListNode * res = dummyNode->next;
        delete dummyNode;
        return res;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * l1 = head;
        ListNode * l2 = reverseList(slow->next);
        slow->next = nullptr;
        
        head = mergeList(l1, l2);
    }
};
