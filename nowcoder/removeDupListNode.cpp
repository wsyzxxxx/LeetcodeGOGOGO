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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
        
        ListNode * curr = pHead->next;
        ListNode ** preCurr = &pHead;
        while (curr) {
            if (curr->val == (*preCurr)->val) {
                while (curr != NULL && curr->val == (*preCurr)->val) {
                    ListNode * next = curr->next;
                    delete curr;
                    curr = next;
                }
                if (curr == NULL) {
                    delete (*preCurr);
                    (*preCurr) = NULL;
                } else {
                    delete (*preCurr);
                    *preCurr = curr;
                    curr = curr->next;
                }
            } else {
                preCurr = &((*preCurr)->next);
                curr = curr->next;
            }
        }
        
        return pHead;
    }
};
