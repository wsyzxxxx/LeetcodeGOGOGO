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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k == 0) {
            return NULL;
        }
        
        ListNode * curr = pListHead;
        for (int i = 0; i < k; i++) {
            if (curr) {
                curr = curr->next;
            } else {
                return NULL;
            }
        }
        
        ListNode * kPreCurr = pListHead;
        while (curr != NULL) {
            curr = curr->next;
            kPreCurr = kPreCurr->next;
        }
        
        return kPreCurr;
    }
};
