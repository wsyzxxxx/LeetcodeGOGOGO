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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
        
        ListNode * preCurr = NULL;
        ListNode * curr = pHead;
        while (curr) {
            ListNode * next = curr->next;
            curr->next = preCurr;
            preCurr = curr;
            curr = next;
        }
        
        return preCurr;
    }
};
