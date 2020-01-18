/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode * constructTree(ListNode * start, ListNode * end) {
        if (start == end) {
            return nullptr;
        }
        
        ListNode * slow = start;
        ListNode * fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode * root = new TreeNode(slow->val);
        root->left = constructTree(start, slow);
        root->right = constructTree(slow->next, end);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        return constructTree(head, nullptr);
    }
};



