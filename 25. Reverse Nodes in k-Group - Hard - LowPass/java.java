/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    private ListNode reverseKNodes(ListNode currHead, int k) {
        if (currHead == null || k == 1) {
            return currHead;
        }
        
        int count = 0;
        ListNode curr = currHead;
        while (curr != null && count < k) {
            count++;
            curr = curr.next;
        }
        
        if (count < k) {
            return currHead;
        }
        
        ListNode nextHead = reverseKNodes(curr, k);
        ListNode before = nextHead;
        curr = currHead;
        count = 0;
        while (count < k) {
            ListNode tempNext = curr.next;
            curr.next = before;
            before = curr;
            curr = tempNext;
            count++;
        }
        
        return before;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return reverseKNodes(head, k);
    }
}