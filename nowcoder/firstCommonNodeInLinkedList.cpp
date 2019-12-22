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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) {
            return NULL;
        }
        
        ListNode * curr1 = pHead1;
        ListNode * curr2 = pHead2;
        int p1Size = 0;
        int p2Size = 0;
        while (curr1) {
            p1Size++;
            curr1 = curr1->next;
        }
        while (curr2) {
            p2Size++;
            curr2 = curr2->next;
        }
        
        curr1 = pHead1;
        curr2 = pHead2;
        if (p1Size > p2Size) {
            while (p1Size > p2Size) {
                curr1 = curr1->next;
                p1Size--;
            }
        } else {
            while (p2Size > p1Size) {
                curr2 = curr2->next;
                p2Size--;
            }
        }
        while (curr1 != NULL && curr2 != NULL && curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        if (curr1) {
            return curr1;
        } else {
            return curr2;
        }
    }
};
