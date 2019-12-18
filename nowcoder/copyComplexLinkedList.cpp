/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
private:
    void cloneList(RandomListNode* head) {
        RandomListNode* curr = head;
        while (curr) {
            RandomListNode* newNode = new RandomListNode(curr->label);
            newNode->next = curr->next;
            newNode->random = NULL;
            curr->next = newNode;
            curr = newNode->next;
        }
    }
    void redirectNewRandom(RandomListNode* head) {
        RandomListNode* curr = head;
        while (curr) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
    }
    RandomListNode* splitList(RandomListNode* head) {
        RandomListNode* newHead = head->next;
        RandomListNode* curr = head;
        RandomListNode* newCurr = head->next;
        while (curr) {
            curr->next = newCurr->next;
            curr = newCurr->next;
            if (curr) {
                newCurr->next = curr->next;
                newCurr = curr->next;
            }
        }
        return newHead;
    }
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) {
            return NULL;
        }
        cloneList(pHead);
        redirectNewRandom(pHead);
        return splitList(pHead);
    }
};
