/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool exist[10002];

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (head == nullptr || G.empty()) {
            return 0;
        }
        
        std::memset(exist, 0, sizeof(exist));
        for (const auto i : G) {
            exist[i] = true;
        }
        
        int count = 0;
        bool inComponent = false;
        ListNode * curr = head;
        while (curr) {
            if (exist[curr->val]) {
                inComponent = true;
            } else if (inComponent) {
                count++;
                inComponent = false;
            }
            curr = curr->next;
        }
        if (inComponent) {
            count++;
        }
        
        return count;
    }
};
