/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL) {
            return pHead2;
        } else if (pHead2 == NULL) {
            return pHead1;
        }
        
        ListNode * newHead = NULL;
        ListNode ** curr = &newHead;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                *curr = pHead1;
                pHead1 = pHead1->next;
            } else {
                *curr = pHead2;
                pHead2 = pHead2->next;
            }
            curr = &((*curr)->next);
        }
        if (pHead1 == NULL) {
            *curr = pHead2;
        } else if (pHead2 == NULL) {
            *curr = pHead1;
        }
        
        return newHead;
    }
};
