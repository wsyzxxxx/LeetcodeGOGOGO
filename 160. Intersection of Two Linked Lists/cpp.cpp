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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        size_t sizeOfListA = 0;
        size_t sizeOfListB = 0;
        
        ListNode * currA = headA;
        ListNode * currB = headB;
        while (currA) {
            sizeOfListA++;
            currA = currA->next;
        }
        while (currB) {
            sizeOfListB++;
            currB = currB->next;
        }
        
        size_t diff = (sizeOfListA > sizeOfListB) ? 
                      (sizeOfListA - sizeOfListB) :
                      (sizeOfListB - sizeOfListA);
        
        currA = headA;
        currB = headB;
        if (sizeOfListA > sizeOfListB) {
            while (diff--) {
                currA = currA->next;
            }
        } else {
            while (diff--) {
                currB = currB->next;
            }
        }
        
        while (currA && currB) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        
        return NULL;
    }
};
