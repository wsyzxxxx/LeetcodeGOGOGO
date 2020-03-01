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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if (k <= 0) {
            return {};
        }
        
        ListNode * curr = root;
        int count = 0;
        while (curr) {
            curr = curr->next;
            count++;
        }
        
        if (k >= count) {
            std::vector<ListNode *> res;
            curr = root;
            while (k) {
                if (curr) {
                    ListNode * temp = curr->next;
                    curr->next = nullptr;
                    res.push_back(curr);
                    curr = temp;
                } else {
                    res.push_back(curr);
                }
                k--;
            }
            
            return res;
        }
        
        std::vector<ListNode *> res;
        int rest = count % k;
        int len = count / k;
        ListNode * currHead = root;
        curr = root;
        count = len + (rest-- > 0 ? 1 : 0);
        while (curr) {
            count--;
            if (count == 0) {
                res.push_back(currHead);
                currHead = curr->next;
                curr->next = nullptr;
                curr = currHead;
                count = len + (rest-- > 0 ? 1 : 0);
            } else {
                curr = curr->next;
            }
        }
        
        return res;
    }
};
