/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            return NULL;
        }
        
        ListNode * slow = pHead;
        ListNode * fast = pHead->next;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        int cycleSize = 1;
        if (slow == fast) {
            while (slow != fast->next) {
                fast = fast->next;
                cycleSize++;
            }
        }
        
        fast = pHead;
        while (cycleSize--) {
            fast = fast->next;
        }
        
        slow = pHead;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
