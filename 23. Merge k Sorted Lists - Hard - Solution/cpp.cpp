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
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
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
    ListNode * mergeKList(std::vector<ListNode *> & lists, int start, int end) {
        if (end <= start) {
            return nullptr;
        }
        if (end == start+1) {
            return lists[start];
        }
        if (end == start+2) {
            return mergeTwoLists(lists[start], lists[start+1]);
        } else {
            int mid = (end + start) / 2;
            ListNode * l1 = mergeKList(lists, start, mid);
            ListNode * l2 = mergeKList(lists, mid, end);
            return mergeTwoLists(l1, l2);
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKList(lists, 0, lists.size());
    }
};
